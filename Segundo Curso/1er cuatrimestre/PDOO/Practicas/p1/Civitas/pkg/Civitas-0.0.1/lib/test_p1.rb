# encoding:utf-8
module Civitas
  
  require_relative "dado"
  require_relative "mazo_sorpresas"
  require_relative "diario"
  require_relative "sorpresa"
  require_relative "tipo_casilla"
  require_relative "tipo_sorpresa"
  require_relative "operaciones_juego"
  require_relative "estados_juego"
  
  class TestP1
    def self.main
      dado = Dado.instance
#---------------------------------------------     
#     i=0
#     until i==100
#       print dado.quien_empieza(4)
#       print " "
#       i+=1
#     end
# --------------------------------------------
#     puts dado.tirar
#     puts dado.get_ultimo_resultado
#      
#     dado.set_debug(true)
#      
#     puts dado.tirar
#     puts dado.get_ultimo_resultado
#      
#      
#     dado.set_debug(false)
#      
#     puts dado.tirar
#     puts dado.get_ultimo_resultado
#      
#     dado.set_debug(true)
#      
#     puts dado.tirar
#     puts dado.get_ultimo_resultado
#       
#     dado.set_debug(false)
#       
#     puts dado.tirar
#     puts dado.get_ultimo_resultado
#      
#--------------------------------------------
#      
#     if dado.salgo_de_la_carcel
#       puts 'Puedo salir de la cárcel'
#     else
#       puts 'No puedo salir de la cárcel'
#     end
#-----------------------------------------------
#
#     puts Tipo_Casilla::CALLE
#     puts Tipo_Sorpresa::IRCARCEL
#     puts Operaciones_Juego::GESTIONAR
#     puts Estados_juego::INICIO_TURNO
#      
#------------------------------------------------    
#
#      mazo = MazoSorpresas.new
#      diario = Diario.instance
#      
#      sorpresa1 = Sorpresa.new('s1')
#      sorpresa2 = Sorpresa.new('s2')
#      
#      mazo.al_mazo(sorpresa1)
#      mazo.al_mazo(sorpresa2)
#      
#      mazo.siguiente
#      
#      mazo.inhabilitar_carta_especial(sorpresa2)
#      diario.leer_evento
#      mazo.habilitar_carta_especial(sorpresa2)
#      diario.leer_evento
#      
#-----------------------------------------------

      
    end
  end
  
  TestP1.main
end