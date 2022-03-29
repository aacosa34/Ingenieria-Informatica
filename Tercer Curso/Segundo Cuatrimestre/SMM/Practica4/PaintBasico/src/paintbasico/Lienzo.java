/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JPanel.java to edit this template
 */
package paintbasico;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Point;

/**
 *
 * @author adri
 */
public class Lienzo extends javax.swing.JPanel {
    enum Herramienta {PUNTO, LINEA, RECTANGULO, ECLIPSE};
    Point p1 = new Point(-20,-20), p2 = new Point(-20,-20);
    Color color = Color.black;
    boolean relleno = false;
    Herramienta herramienta = Herramienta.PUNTO;

    /**
     * Creates new form Lienzo
     */
    public Lienzo() {
        initComponents();
    }
    
    @Override
    public void paint(Graphics g){
        super.paint(g);
        g.setColor(color);
        switch(herramienta){
            case PUNTO:
                g.fillOval(p1.x-5, p1.y-5, 10, 10);
            break;
            
            case LINEA:
                g.drawLine(p1.x, p1.y, p2.x, p2.y);
            break;
            
            case RECTANGULO:
                if(relleno)
                    g.fillRect(Math.min(p1.x,p2.x), Math.min(p1.y,p2.y),
                               Math.abs(p2.x-p1.x), Math.abs(p2.y-p1.y));
                else
                    g.drawRect(Math.min(p1.x,p2.x), Math.min(p1.y,p2.y),
                               Math.abs(p2.x-p1.x), Math.abs(p2.y-p1.y));
            break;
            
            case ECLIPSE:
                if(relleno)
                    g.fillOval(Math.min(p1.x,p2.x), Math.min(p1.y,p2.y),
                               Math.abs(p2.x-p1.x), Math.abs(p2.y-p1.y));
                else
                    g.drawOval(Math.min(p1.x,p2.x), Math.min(p1.y,p2.y),
                               Math.abs(p2.x-p1.x), Math.abs(p2.y-p1.y));
            break;
             
        }
        
    }
    
    public Color getColor() {
        return color;
    }

    public void setColor(Color color) {
        this.color = color;
    }
    
    public boolean isRelleno() {
        return relleno;
    }

    public void setRelleno(boolean relleno) {
        this.relleno = relleno;
    }
    
    public Herramienta getHerramienta() {
        return herramienta;
    }

    public void setHerramienta(Herramienta herramienta) {
        this.herramienta = herramienta;
    }
    
    public void setBlank(){
        p1 = new Point(-10,-10);
        p2 = new Point(-10,-10);
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        setBackground(java.awt.Color.white);
        addMouseMotionListener(new java.awt.event.MouseMotionAdapter() {
            public void mouseDragged(java.awt.event.MouseEvent evt) {
                formMouseDragged(evt);
            }
        });
        addMouseListener(new java.awt.event.MouseAdapter() {
            public void mousePressed(java.awt.event.MouseEvent evt) {
                formMousePressed(evt);
            }
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                formMouseClicked(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(this);
        this.setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 557, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 435, Short.MAX_VALUE)
        );
    }// </editor-fold>//GEN-END:initComponents

    private void formMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_formMouseClicked
        p1 = evt.getPoint();
        this.repaint();
    }//GEN-LAST:event_formMouseClicked

    private void formMousePressed(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_formMousePressed
        p1 = evt.getPoint();
    }//GEN-LAST:event_formMousePressed

    private void formMouseDragged(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_formMouseDragged
        p2 = evt.getPoint();
        this.repaint();
    }//GEN-LAST:event_formMouseDragged


    // Variables declaration - do not modify//GEN-BEGIN:variables
    // End of variables declaration//GEN-END:variables
}