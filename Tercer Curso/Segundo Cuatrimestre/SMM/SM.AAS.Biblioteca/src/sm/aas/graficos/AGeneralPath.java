/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package sm.aas.graficos;

import java.awt.geom.AffineTransform;
import java.awt.geom.GeneralPath;
import java.awt.geom.Point2D;

/**
 *
 * @author adrian
 */
public class AGeneralPath extends GeneralPath.Double {
    
    public void setLocation(Point2D pos){
        Point2D loc = this.getCurrentPoint();
        AffineTransform at;
        at = AffineTransform.getTranslateInstance(pos.getX() - loc.getX(), pos.getY() - loc.getY());
        this.transform(at);
    }
    
    @Override
    public String toString(){
        return "Trazo libre";
    }
}
