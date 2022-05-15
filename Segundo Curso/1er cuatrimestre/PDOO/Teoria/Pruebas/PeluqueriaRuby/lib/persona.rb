module Basico
   
 module ColorPelo
 MORENO= :moreno
 CASTANO= :castano
 RUBIO= :rubio
 PELIROJO= :pelirojo
 end

 class Persona
   
 def initialize (n, e, p, a) # " constructor "
    # Atributos de instancia ( son siempre privados )
    @nombre=n
    @edad=e
    @pelo=p
    @altura=a
 end

 public # no es necesario , pues los métodos son públicos por defecto
 
 def saluda # Método público de instancia
     puts "Hola , soy "+@nombre
 end
 
 def pedir_cita(peluqueria)  #Método de instancia
     saluda
     return peluqueria.dar_cita #envía mensaje a peluquería para que ésta le dé la cita 
 end
 
 def es_alta
    return @altura > 180
 end
 
 def to_s
    "Nombre: #{@nombre}, Edad: #{@edad}, Color de pelo: #{@pelo}, Altura: #{@altura}"
 end
 
 def setColorPelo (color)
   @pelo=color
 end

end

end
