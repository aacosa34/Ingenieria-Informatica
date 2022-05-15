# encoding:utf-8

module Civitas
  class MazoSorpresas
    def initialize (d=false)
      @sorpresas = []
      @barajada
      @usadas = 0
      @debug=d
      @cartas_especiales = []
      @ultima_sorpresa
      if @debug
        ocurre_evento('Mazo de Sorpresas en modo debug')
      end
    end
    
    def al_mazo (s)
      unless @barajada then
        @sorpresas<<s
      end
    end
    
    def siguiente
      if !@barajada || @usadas==@sorpresas.size     # Comprobación de si ha sido barajada y las cartas usadas hasta el momento
        unless @debug then                          # Si no está activado el debug, se mezclan
          @sorpresas.shuffle
        end
        @usadas=0
        @barajada=true
      end                                           # Cogemos la primera carta y la ponemos al final, además de guardarla en ultima_sorpresa
      @usadas+=1
      @ultima_sorpresa=@sorpresas[0]
      @sorpresas.delete_at(0)
      @sorpresas<<@ultima_sorpresa
      @ultima_sorpresa
    end
    
    def inhabilitar_carta_especial (sorpresa)
      if @sorpresa.include?(sorpresa)
        @cartas_especiales<<@sorpresas.index(sorpresa)
        @sorpresa.delete_at(@sorpresas.index(sorpresa))
        ocurre_evento('Se deshabilita la carta especial'+sorpresa.to_s) # No se si está bien
      end
    end
    
    def habilitar_carta_especial (sorpresa)
      if @cartas_especiales.include?(sorpresa)
        @sorpresas<<@cartas_especiales.index(sorpresa)
        @cartas_especiales.delete_at(@cartas_especiales.index(sorpresa))
        ocurre_evento('Se habilita la carta especial'+sorpresa.to_s)
      end
    end
    
  end
end