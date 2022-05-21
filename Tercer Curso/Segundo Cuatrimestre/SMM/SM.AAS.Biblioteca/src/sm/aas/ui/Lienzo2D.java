/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JPanel.java to edit this template
 */
package sm.aas.ui;

import java.awt.AlphaComposite;
import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Composite;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Point;
import java.awt.Rectangle;
import java.awt.RenderingHints;
import java.awt.Shape;
import java.awt.Stroke;
import java.awt.geom.Line2D;
import java.awt.geom.Point2D;
import java.awt.geom.QuadCurve2D;
import java.awt.image.BufferedImage;
import java.util.ArrayList;
import sm.aas.eventos.LienzoEvent;
import sm.aas.eventos.LienzoListener;
import sm.aas.graficos.AElipse2D;
import sm.aas.graficos.AGeneralPath;
import sm.aas.graficos.ALinea2D;
import sm.aas.graficos.AQuadCurve2D;
import sm.aas.graficos.ARectangulo2D;

/**
 *
 * @author adrian
 */
public class Lienzo2D extends javax.swing.JPanel {
    // Enumerado con las formas posibles a usar
    public enum Formas {TRAZO_LIBRE, LINEA, RECTANGULO, ELIPSE, QUAD_CURVE};
    private Formas formaActiva;
    
    // Variables auxiliares para pintar las formas
    private Point pAux;
    private ArrayList<Shape> vShape;
    private Shape s;
    private boolean volcado;
    private int pasoCurva;
    
    // Propiedades de las figuras
    private boolean relleno, mover, trans_activa, alisado;
    private Color color;
    private Stroke stroke;
    private Composite comp;
    private final float transparencia = 0.5f;
    private RenderingHints render;
    
    // Variables relacionadas con procesamiento de imagenes
    private BufferedImage img;
    
    // Manejadores de lienzo
    ArrayList<LienzoListener> lienzoEventListeners;
    

    /**
     * Creates new form Lienzo2D
     */
    public Lienzo2D() {
        // Inicializacion de todos los atributos
        formaActiva = Formas.TRAZO_LIBRE;
        pAux = new Point();
        vShape = new ArrayList<>();
        s = null;
        volcado = relleno = mover = trans_activa = alisado = false;
        pasoCurva = 0;
        color = Color.black;
        render = null;
        comp = null;
        stroke = new BasicStroke();
        lienzoEventListeners = new ArrayList<>();
        img = null;
        initComponents();
    }
    
    @Override
    public void paint(Graphics g) {
        super.paint(g);
        
        Graphics2D g2d = (Graphics2D) g;
        
        if(img!=null){
            g2d.drawImage(img, 0, 0, this);            
        }
        
        g2d.setPaint(color);
        g2d.setStroke(stroke);        
        
        if (trans_activa) {
            g2d.setComposite(comp);
        }
        
        if (alisado){
            g2d.setRenderingHints(render);
        }
        
        for (Shape forma : vShape) {
            if (relleno) {
                g2d.fill(forma);
                if(forma instanceof ALinea2D) g2d.draw(forma);
            }else{
                g2d.draw(forma);
            }
        } 
        
    }
    
    // Metodo paint especial para volcado
    void paintVolcado(Graphics2D g2dimg){
        // Establecemos las propiedades de las figuras a pintar
        g2dimg.setPaint(color);
        g2dimg.setStroke(stroke);        

        if (trans_activa) {
            g2dimg.setComposite(comp);
        }

        if (alisado){
            g2dimg.setRenderingHints(render);
        }
        
        // Pintamos todas las figuras contenidas en la lista y la limpiamos
        if(!vShape.isEmpty()){
            for(Shape forma : vShape){
                if(relleno){
                    g2dimg.fill(forma);
                }else{
                    g2dimg.draw(forma);
                }
            }
            vShape.clear();
        }
        
        // Cada vez que pintemos, usamos la figura creada en el pressed y la
        // plasmamos directamente en el lienzo
        if(s!=null){
            if(relleno){
                g2dimg.fill(s);
            }else{
                g2dimg.draw(s);
            }
        }
        
    }

    public boolean isRelleno() {
        return relleno;
    }

    public void setRelleno(boolean relleno) {
        this.relleno = relleno;
    }

    public Color getColor() {
        return color;
    }

    public void setColor(Color color) {
        this.color = color;
    }

    public void setGrosor(float grosor){
        stroke = new BasicStroke(grosor);
    }
    
    public float getGrosor(){
        return ((BasicStroke)stroke).getLineWidth();
    }

    public Formas getFormaActiva() {
        return formaActiva;
    }

    public void setFormaActiva(Formas formaActiva) {
        this.formaActiva = formaActiva;
    }

    public boolean isMover() {
        return mover;
    }

    public void setMover(boolean mover) {
        this.mover = mover;
    }

    public boolean isTrans_activa() {
        return trans_activa;
    }

    public void setTrans_activa(boolean trans_activa) {
        if(trans_activa && comp == null){
            comp = AlphaComposite.getInstance(AlphaComposite.SRC_ATOP, transparencia);
        }
        
        this.trans_activa = trans_activa;
    }

    public boolean isAlisado() {
        return alisado;
    }

    public void setAlisado(boolean alisado) {
        if(alisado && render == null){
            render = new RenderingHints(RenderingHints.KEY_ANTIALIASING,
                                        RenderingHints.VALUE_ANTIALIAS_ON);
        }
        
        this.alisado = alisado;
    }
    
    private Shape getSelectedShape(Point2D p) {
        for (Shape forma : vShape) {
            if (forma.contains(p)) {
                return forma;
            }
        }
        return null;
    }

    public BufferedImage getImage() {
        return img;
    }
    
    // Metodo para poder guardar las imagenes junto con las figuras que hemos
    // dibujado encima
    public BufferedImage getImage(boolean drawVector){
        if(drawVector){
            BufferedImage imgout = new BufferedImage(img.getWidth(),
                                                     img.getHeight(),
                                                     img.getType());
            boolean opacoActual = this.isOpaque();
            if(img.getColorModel().hasAlpha()){ // Desactiva la opacidad en el caso de que la imagen tenga canal alfa
                this.setOpaque(false);
            }
            this.paint(imgout.createGraphics());
            this.setOpaque(opacoActual);
            return imgout;
        }
        else{
            return img;
        }
    }

    public void setImage(BufferedImage img) {
        this.img = img;
        
        if (img != null) {
            setPreferredSize(new Dimension(img.getWidth(), img.getHeight()));
        }
    }

    public boolean isVolcado() {
        return volcado;
    }

    public void setVolcado(boolean volcado) {
        if(volcado){
            notifyOverturnChanged(new LienzoEvent(this, volcado));
            Graphics2D g2dimg = img.createGraphics();
            paintVolcado(g2dimg);
        }
        
        this.volcado = volcado;
    }

    public ArrayList<Shape> getvShape() {
        return vShape;
    }
    
    public void addLienzoListener(LienzoListener listener) {
        if (listener != null) {
            lienzoEventListeners.add(listener);
        }
    }

    private void notifyShapeAddedEvent(LienzoEvent evt) {
        if (!lienzoEventListeners.isEmpty()) {
            for (LienzoListener listener : lienzoEventListeners) {
                listener.shapeAdded(evt);
            }
        }
    }
    
    private void notifyOverturnChanged(LienzoEvent evt) {
        if (!lienzoEventListeners.isEmpty()){
            for(LienzoListener listener : lienzoEventListeners) {
                listener.overturnChanged(evt);
            }
        }
    }

    private void notifyPropertyChangeEvent(LienzoEvent evt) {
        if (!lienzoEventListeners.isEmpty()) {
            for (LienzoListener listener : lienzoEventListeners) {
                listener.propertyChange(evt);
            }
        }
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
            public void mouseReleased(java.awt.event.MouseEvent evt) {
                formMouseReleased(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(this);
        this.setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 400, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 300, Short.MAX_VALUE)
        );
    }// </editor-fold>//GEN-END:initComponents

    private void formMousePressed(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_formMousePressed
        
        pAux = evt.getPoint();
        
        
        if(mover){
            s = this.getSelectedShape(pAux);
        }
        else{
            switch(formaActiva){
                case TRAZO_LIBRE:
                    s = new AGeneralPath();
                    ((AGeneralPath)s).moveTo(pAux.x, pAux.y);
                break;
                
                case LINEA:
                    s = new ALinea2D();
                break;
                
                case RECTANGULO:
                    s = new ARectangulo2D(pAux);
                break;
                
                case ELIPSE:
                    s = new AElipse2D();
                break;
                
                case QUAD_CURVE:
                    if(pasoCurva == 0){
                        s = new AQuadCurve2D();
                        pasoCurva++;
                    }
                break;
                
            }
            
        }
    }//GEN-LAST:event_formMousePressed

    private void formMouseDragged(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_formMouseDragged
        if(mover && !volcado){
            if(s instanceof ARectangulo2D){
                ((Rectangle)s).setLocation(evt.getPoint());
            }
            else if(s instanceof AElipse2D){
                ((AElipse2D)s).setLocation(evt.getPoint());
            }
            else if(s instanceof ALinea2D){
                ((ALinea2D)s).setLocation(evt.getPoint());
            }
            else if(s instanceof AGeneralPath){
                ((AGeneralPath)s).setLocation(evt.getPoint());
            }   
        }else{
            if(s instanceof Line2D) ((Line2D)s).setLine(pAux,evt.getPoint());
            else if(s instanceof ARectangulo2D)
                ((ARectangulo2D)s).setFrameFromDiagonal(pAux, evt.getPoint());
            else if(s instanceof AElipse2D)
                ((AElipse2D)s).setFrameFromDiagonal(pAux, evt.getPoint());
            else if(s instanceof AGeneralPath){
                ((AGeneralPath)s).lineTo(evt.getX(), evt.getY());
            }
            else if(s instanceof AQuadCurve2D){
                if(pasoCurva == 1){
                    ((AQuadCurve2D)s).setCurve(pAux, pAux, evt.getPoint());
                }
                else if(pasoCurva == 2){
                    ((AQuadCurve2D)s).setCurve(((QuadCurve2D)s).getP1(), evt.getPoint(), ((QuadCurve2D)s).getP2());
                }
            }
            
            if(!volcado){
                vShape.add(s);
            }
        }
        
        this.repaint();
    }//GEN-LAST:event_formMouseDragged

    private void formMouseReleased(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_formMouseReleased
        if(pasoCurva == 1){
            pasoCurva++;
        }else{
            pasoCurva=0;
        }
        
        if(!volcado){
            if(pasoCurva != 1){
                notifyShapeAddedEvent(new LienzoEvent(this,s,color));
            }
                
        }
        else{
            if(pasoCurva != 2 && !mover){
                Graphics2D g2dimg = img.createGraphics();
                paintVolcado(g2dimg);
            }
           
        }
        
        
        
        this.formMouseDragged(evt);
    }//GEN-LAST:event_formMouseReleased


    // Variables declaration - do not modify//GEN-BEGIN:variables
    // End of variables declaration//GEN-END:variables
}
