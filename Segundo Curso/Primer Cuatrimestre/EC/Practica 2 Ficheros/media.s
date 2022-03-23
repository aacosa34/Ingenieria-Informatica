.section .data
# lista:		.int 1,2,10,  1,2,0b10,  1,2,0x10
# lista:		.int 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1
lista:      .int 0x1000000,0x1000000,0x1000000,0x1000000
            .int 0x1000000,0x1000000,0x1000000,0x1000000
            .int 0x1000000,0x1000000,0x1000000,0x1000000
            .int 0x1000000,0x1000000,0x1000000,0x1000000  
longlista:	.int   (.-lista)/4
# resultado:	.int   0
resultado:	.quad	0
#  formato: 	.asciz	"suma = %u = 0x%x hex\n"
formato:	.asciz	"suma = %lu = 0x%lx hex\n"

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
	mov  %eax, resultado
	mov  %edx, resultado+4	# NEW: EDX a 4B MSB (little endian)

	# require libC
	mov   $formato, %rdi
#	mov   resultado,%esi
#	mov   resultado,%edx
	mov   resultado,%rsi	# ahora 64 bits
	mov   resultado,%rdx	# ahora 64 bits
	mov          $0,%eax	# varargin sin xmm
	call  printf		# == printf(formato, res, res);

	# require libC
#	mov  resultado, %edi
	mov  $0, %edi
	call _exit		# ==  exit(resultado)

suma:
#	push     %rdx	# Ya no hace falta, resultado en (EDX:EAX) concatenado
	mov  $0, %eax
	mov  $0, %edx	# NEW: acumularemos en el EDX los acarreos
#	mov  $0, %rdx
	mov  $0, %rsi	# El indice ya no puede ser RDX, usamos EDX para acumular acarreo

bucle:
#	add  (%rbx,%rdx,4), %eax
	add  (%rbx,%rsi,4), %eax	# El nuevo indice para el bucle es RSI
	jnc	  noacar				# NEW: salta a esa etiqueta si no hay acarreo
#	inc   %rdx
	inc   %edx					# NEW: guardamos acarreos en EDX

noacar: inc   %rsi				# El nuevo indice para el bucle es RSI
#	cmp   %rdx,%rcx
	cmp   %rsi,%rcx				# El nuevo indice para el bucle es RSI
	jne    bucle
#	pop   %rdx

	ret

