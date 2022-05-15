
package aplicacionperros;

public class Perro {
    private String raza;
    private int peso;
    boolean agresivo; /*Si no pongo nada delante significa que es de paquete,
                       que es visible para otros paquetes*/
    public String nombre;
    
    public Perro(String raza, int p, String n){ // Constructor (dar valor a todos los atributos
        this.raza = raza;                     // Si se le pone this, se refiere al atributo
        peso = p;
        agresivo = false;
        nombre = n;
    }
    
    public void getNombre(){ //Metodo consultor (get delante)
        return nombre;
    }
    
    public void ladrar(){ // Comportamiento para objeto de la clase
        System.out.println("guau guau");
    }
    
    public void setNombre(String nuevoNombre){ // Modificador
        nombre = nuevoNombre;
    }
    
    public void ponteAgresivo() {  
        agresivo = true;
    }
    
    public boolean getAgresivo(){
        return agresivo;
    }
    
    
}