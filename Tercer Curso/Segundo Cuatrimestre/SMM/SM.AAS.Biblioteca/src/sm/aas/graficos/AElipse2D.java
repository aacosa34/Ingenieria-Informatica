/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package sm.aas.graficos;

import java.awt.geom.Ellipse2D;
import java.awt.geom.Point2D;

/**
 *
 * @author adrian
 */
public class AElipse2D extends Ellipse2D.Double {
    
    public void setLocation(Point2D pos) {
        double dx = pos.getX() - this.getX()+this.getWidth();
        double dy = pos.getY() - this.getY()+this.getHeight();
        Point2D newp2 = new Point2D.Double(this.getX() + dx, this.getY() + dy);
        this.setFrameFromDiagonal(pos, newp2);
    }
}
