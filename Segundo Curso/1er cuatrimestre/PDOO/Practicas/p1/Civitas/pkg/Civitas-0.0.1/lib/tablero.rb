# encoding:utf-8

module Civitas
  require_relative "casilla"
  class Tablero
    
    attr_reader :num_casilla_carcel # Consultor de atributos
    
    def initialize (n)  # Constructor con la posición de la casilla de la carcel como argumento
      if n>=1
        @num_casilla_carcel=n
      else
        @num_casilla_carcel=1
      end
      casilla_salida = Casilla.new('Salida')
      @casillas=[casilla_salida]
      @por_salida=0
      @tiene_juez=false
    end
    
    def correcto
      @casillas.size>@num_casilla_carcel && @tiene_juez
    end
    
    def correcto (num_casilla)
      correcto && (num_casilla >= 0 && num_casilla <= @casillas.size)
    end
    
    def get_por_salida
      @por_salida
      
      if @por_salida>0
        @por_salida-=1
      end
    end
    
    def aniade_casilla (casilla)   # Método que añade una casilla y comprueba si la última es la cárcel
      casilla_carcel = Casilla.new('Carcel')
      if @casillas.size == @num_casilla_carcel
        @casillas<<casilla_carcel
      end
      
      @casillas<<casilla
      
      if @casillas.size == @num_casilla_carcel
        @casillas<<casilla_carcel
      end
    end
    
    def aniade_juez
      casilla_juez=Casilla.new('Juez')
      unless @tiene_juez then
        @casillas<<casilla_juez
        @tiene_juez=true
      end
    end
    
    def get_casilla (indice)
      if correcto(indice)
        @casillas[indice]
      else
        nil
      end
    end
    
    def nueva_posicion (actual, tirada)
      unless correcto then
        valor_incorrecto=-1
        valor_incorrecto
      else
        pos_nueva=actual+tirada
        if pos_nueva > @casillas.size
          @por_salida+=1
        end
        pos_nueva=pos_nueva%@casillas.size  #Actualizar el valor de pos_nueva a uno que esé dentro del tablero
        pos_nueva
      end  
    end
    
    def calcular_tirada (origen, destino)
      if origen>destino
        destino-origen+@casillas.size
      else
        destino-origen
      end
    end
    
  end
end