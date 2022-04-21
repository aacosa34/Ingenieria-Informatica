/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package sm.aas.graficos;

import java.awt.geom.Line2D;
import java.awt.geom.Point2D;

/**
 *
 * @author adrian
 */
public class JLinea2D extends Line2D.Double {
    
    public boolean isNear(Point2D p){
        return this.ptLineDist(p)<=2.0;
    }
    
    @Override
    public boolean contains(Point2D p){
        return isNear(p);
    }
    
    public void setLocation(Point2D pos) {
        double dx = pos.getX() - this.getX1();
        double dy = pos.getY() - this.getY1();
        Point2D newp2 = new Point2D.Double(this.getX2() + dx, this.getY2() + dy);
        this.setLine(pos, newp2);
    }
}
