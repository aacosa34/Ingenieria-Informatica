
package aplicacionperro;

public class AplicacionPerros {
    
    public static void main(String[] args) {
        Perro perrilla= new Perro("Chiguagua", 5, "Mimi");
        
        System.out.println(perrilla.getNombre()); //Envio de mensaje
        
        perrilla.ladrar();
        
        perrilla.setNombre("Filomena");
        
        System.out.println(perrilla.getNombre());
        
        perrilla.ponteAgresivo();
        
        System.out.println(perrilla.getAgresivo());        
          
    }
    
}
