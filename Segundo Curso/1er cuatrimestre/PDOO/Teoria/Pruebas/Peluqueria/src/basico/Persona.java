
package basico ;

import java.time.LocalDateTime;

 // Enumerado con visibilidad de paquete. Ver diferencias con visibilidad publica 
/*public*/ enum ColorPelo { MORENO, CASTAÑO, RUBIO, PELIROJO }


public class Persona { // Clase con visibilidad pública
 // Atributos de instancia privados
 private String nombre ; 
 private int edad ;
 private ColorPelo pelo ;
 private int altura ;

 public Persona ( String n , int e , ColorPelo p, int a ) { // "Constructor" público
     nombre = n ;
     edad = e ;
     pelo = p ;
     altura = a ;
 }

 void saluda() { // Visibilidad de paquete. Método de instancia
 System.out.println( "Hola , soy "+nombre );
 }
 
 boolean esAlta() {
     return altura > 180 ;
 }
 
 public String toString() {  // Visibilidad entre paquetes. 
     return "Nombre: "+nombre+"\nEdad: "+edad+"\nAltura: "+altura 
             +"\nColor de Pelo: "+pelo;
 }
 
 public void SetColorDePelo (ColorPelo color) { // Visibilidad entre paquetes
     pelo = color;
 }
 
 public String anularCita () {
     return nombre+" quiere anular su cita.";
 }

 
LocalDateTime pedirCita(Peluqueria peluqueria) {// Visibilidad de paquete. Método de instancia
     saluda();
     return peluqueria.darCita(); //envía mensaje a peluquería para que ésta le dé la cita
 }
 



 }