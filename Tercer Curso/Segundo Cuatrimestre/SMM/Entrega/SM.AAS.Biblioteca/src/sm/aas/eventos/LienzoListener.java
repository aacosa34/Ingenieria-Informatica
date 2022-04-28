/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Interface.java to edit this template
 */
package sm.aas.eventos;

import java.util.EventListener;

/**
 *
 * @author adrian
 */
public interface LienzoListener extends EventListener{
    public void shapeAdded(LienzoEvent evt);
    public void propertyChange(LienzoEvent evt);
}
