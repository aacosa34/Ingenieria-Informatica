# encoding:utf-8

require 'singleton'

module Civitas
  require_relative "diario"
  
  class Dado
    include Singleton
    
    
    def initialize
      @random
      @ultimo_resultado
      @debug=false
      @salida_carcel=5
    end
    
    def tirar  # Método para tirar el dado
      if !@debug 
        @random=rand(1..6)
      else
        @random=1
      end
      @ultimo_resultado=@random
      @random
    end
    
    def salgo_de_la_carcel  # Devuelve true si puede salir de la cárcel o false si no puede salir
      tirar
      @random==@salida_carcel
    end
    
    def quien_empieza (n)  # Devuelve un valor que indica que jugador empieza a jugar
      @random=rand(0..(n-1))  # Return para asegurar que devuelve un valor (creo que se puede quitar)
      return @random
    end
    
    def set_debug (d)
      @debug=d
      evento_debug = Diario.instance
      evento_debug.ocurre_evento('Dado en modo debug')
    end
    
    def get_ultimo_resultado
      @ultimo_resultado
    end
    
  end
end
