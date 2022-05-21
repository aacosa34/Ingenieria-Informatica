/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package sm.aas.eventos;

/**
 *
 * @author adrian
 */
public class LienzoAdapter implements LienzoListener{

    @Override
    public void shapeAdded(LienzoEvent evt) {
        System.out.println("Figura " +evt.getForma()+" añadida");
    }
    
    @Override
    public void overturnChanged(LienzoEvent evt){
        System.out.println("Volcado establecido a " + evt.isVolcado());
    }

    @Override
    public void propertyChange(LienzoEvent evt) {
        System.out.println("Propiedad cambiada");
    }
    
}
