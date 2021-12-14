.section .data
.section .data
#ifndef TEST
#define TEST 20
#endif
        .macro linea # Media / Resto - Comentario
    #if TEST==1 // 1 / 8
            .int 1, 2, 1, 2
    #elif TEST==2 // -1 /-8
            .int -1,-2,-1,-2
    #elif TEST==3
            .int 0x7fffffff, 0x7fffffff, 0x7fffffff, 0x7fffffff
    #elif TEST==4
            .int 0x80000000, 0x80000000, 0x80000000, 0x80000000
    #elif TEST==5
            .int 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
    #elif TEST==6
            .int 2000000000, 2000000000, 2000000000, 2000000000
    #elif TEST==7
            .int 3000000000, 3000000000, 3000000000, 3000000000
    #elif TEST==8
            .int -2000000000, -2000000000, -2000000000, -2000000000
    #elif TEST==9
            .int -3000000000, -3000000000, -3000000000, -3000000000
    #elif TEST>=10 && TEST<=14
            .int 1, 1, 1, 1 # linea0 + 3lineas, casi todo a 1
    #elif TEST>=15 && TEST<=19
            .int -1,-1,-1,-1 # linea0 + 3lineas, casi todo -1
    #else
            .error "Definir TEST entre 1..19"
    #endif
            .endm

    # mayoría ejemplos linea0 = linea => lista tiene 4 lineas normales
        .macro linea0 # Media / Resto - Comentario
    #if TEST>=1 && TEST<=9
            linea # casi siempre 4 lineas iguales
    #elif TEST==10 // 1 / 0 - equiv toda lista 1
            .int 0, 2, 1, 1
    #elif TEST==11
            .int 1,2,1,1
    #elif TEST==12
            .int 8,2,1,1
    #elif TEST==13
            .int 15,2,1,1
    #elif TEST==14
            .int 16,2,1,1    
    #elif TEST==15 // -1 / 0 - equiv TEST05
            .int 0,-2,-1,-1
    #elif TEST==16
            .int -1,-2,-1,-1
    #elif TEST==17
            .int -8,-2,-1,-1
    #elif TEST==18
            .int -15,-2,-1,-1
    #elif TEST==19 // ? / ?
            .int -16,-2,-1,-1
    #else
            .error "Definir TEST entre 1..19"
    #endif
            .endm
			
lista:        linea0
        .irpc i,123
			    linea
	   .endr
longlista:	.int   (.-lista)/4
media:	    .int	0
resto:      .int    0

formato:	.ascii "media \t = %11d \t resto \t = %11d \n"
            .asciz "\t = 0x %08x \t \t = 0x %08x\n"

# opción: 1) no usar printf, 2)3) usar printf/fmt/exit, 4) usar tb main
# 1) as  suma.s -o suma.o
#    ld  suma.o -o suma					1232 B
# 2) as  suma.s -o suma.o				6520 B
#    ld  suma.o -o suma -lc -dynamic-linker /lib64/ld-linux-x86-64.so.2
# 3) gcc suma.s -o suma -no-pie –nostartfiles		6544 B
# 4) gcc suma.s -o suma	-no-pie				8664 B

.section .text
# _start: .global _start
main: .global  main

	mov     $lista, %rbx
	mov  longlista, %ecx
	call suma		# == suma(&lista, longlista);
	mov  %eax, media
	mov  %edx, resto	# EDX a 4B MSB (little endian)

	# require libC
    mov %edx, %ecx  # res_MSB
    mov %eax, %r8d  # res_LSB

	mov   $formato, %rdi
	mov   resultado,%rsi	# ahora 64 bits
	mov   resultado,%rdx	# ahora 64 bits
	mov          $0,%eax	# varargin sin xmm
	call  printf		# == printf(formato, media, resto, media, resto);

	# require libC
	mov  $0, %edi
	call _exit		# ==  exit(resultado)

suma:
#	mov  $0, %eax
#	mov  $0, %edx
    mov $0, %ebp    # Acumularemos en estos dos registros porque son los que tenemos libres
    mov $0, %edi
	mov  $0, %rsi	# El indice ya no puede ser RDX, usamos EDX para acumular acarreo

bucle:
#	add  (%rbx,%rsi,4), %eax
    mov  (%rbx,%rsi,4), %eax
    cltd                # Ver tabla 5
    add   %eax, %edi  
    adc   %edx, %ebp    # sumamos el acarreo en EBP

    inc   %rsi			# El nuevo indice para el bucle es RSI
	cmp   %rsi,%rcx		# El nuevo indice para el bucle es RSI
	jne   bucle

    mov   %edi, %eax    # Para hacer el printf
    mov   %ebp, %edx    # suma esta en EDX:EAX

    idiv  %ecx

	ret

