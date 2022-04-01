/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */
package practica5;

import java.awt.AlphaComposite;
import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Composite;
import java.awt.Font;
import java.awt.GradientPaint;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.GraphicsEnvironment;
import java.awt.Paint;
import java.awt.Point;
import java.awt.Rectangle;
import java.awt.RenderingHints;
import java.awt.Shape;
import java.awt.Stroke;
import java.awt.font.TextAttribute;
import java.awt.geom.AffineTransform;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Line2D;
import java.awt.geom.Point2D;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import javax.swing.DefaultComboBoxModel;

/**
 *
 * @author adrian
 */
public class VentanaPrincipal extends javax.swing.JFrame {

    private Point pAux;
    private Rectangle rectangulo;
    private boolean editar = false;
    List<Shape> vShape = new ArrayList();
    GraphicsEnvironment ge = GraphicsEnvironment.getLocalGraphicsEnvironment();
    String[] fuentesSistema = ge.getAvailableFontFamilyNames();

    Ellipse2D clipArea = new Ellipse2D.Float(100, 100, 500, 500);
    private boolean ventanaClipActiva = false;
    private boolean fill = false;
    private String sfuente;
    /**
     * Creates new form VentanaPrincipal
     */
    public VentanaPrincipal() {
        initComponents();
        this.setSize(1000, 1000);
    }

    public void paint(Graphics g) {
        super.paint(g);
        Graphics2D g2d = (Graphics2D) g;
        if (ventanaClipActiva) {
            g2d.setClip(clipArea);
        }
        this.pruebaAtributos(g2d);
        for (Shape s : vShape) {
            if(!fill){
               g2d.draw(s); 
            }
            else{
                g2d.fill(s);
            }
            
        }

    }

    private void pruebaAtributos(Graphics2D g2d) {
        //Trazo
        Stroke trazo;
        float patronDiscontinuidad[] = {15.0f, 15.0f};
        trazo = new BasicStroke(10.0f,
                BasicStroke.CAP_ROUND,
                BasicStroke.JOIN_MITER, 1.0f,
                patronDiscontinuidad, 0.0f);
        g2d.setStroke(trazo);

        //Pintamos una forma de prueba
        g2d.draw(new Line2D.Float(40, 40, 160, 160));

        //Relleno
        Paint relleno;
        relleno = new Color(255, 100, 0);
        g2d.setPaint(relleno);

        g2d.draw(new Rectangle(170, 40, 120, 120));
        g2d.fill(new Rectangle(300, 40, 120, 120));

        // Relleno con gradiente
        Point pc1 = new Point(430, 40), pc2 = new Point(550, 160), pc3 = new Point(480, 80);
        relleno = new GradientPaint(pc1.x, pc1.y, Color.RED, pc2.x, pc2.y, Color.BLUE);
        g2d.setPaint(relleno);
        g2d.fill(new Rectangle(430, 40, 120, 120));

        //Composición
        Composite composicion = null;
        composicion = AlphaComposite.getInstance(AlphaComposite.SRC_ATOP, 0.5f);
        g2d.setComposite(composicion);

        g2d.fill(new Rectangle(190, 100, 200, 190));

        //Transformación
        Rectangle r = new Rectangle(430, 190, 120, 120);
        g2d.draw(r); //Dibujamos rectángulo sin transformación

        AffineTransform transformacion;
        transformacion = AffineTransform.getRotateInstance(Math.toRadians(45.0),
                r.getCenterX(),
                r.getCenterY());
        g2d.setTransform(transformacion);
        g2d.fill(r); // Aqui se dibuja el rectangulo con la transformacion aplicada

        transformacion = AffineTransform.getScaleInstance(0.5, 0.5);
        g2d.setTransform(transformacion);
        g2d.draw(r); // Al dibujar no se pinta en el centro que esperamos
        // Primero hay que llevarla al origen y luego hacer el escalado
        transformacion.setToIdentity();
        transformacion.translate(r.getCenterX(), r.getCenterY());   // Por ultimo llevamos la centro del rectangulo
        transformacion.scale(0.5, 0.5);                             // Despues escalamos
        transformacion.translate(-r.getCenterX(), -r.getCenterY()); // Primero movemos al origen
        g2d.setTransform(transformacion);
        g2d.draw(r);

        // Ejercicio propuesto
        transformacion.setToIdentity();
        transformacion.translate(r.getCenterX(), r.getCenterY());   // Por ultimo llevamos la centro del rectangulo
        transformacion.rotate(Math.toRadians(45.0));
        transformacion.scale(0.25, 0.25);                             // Despues escalamos
        transformacion.translate(-r.getCenterX(), -r.getCenterY()); // Primero movemos al origen
        g2d.setTransform(transformacion);
        g2d.draw(r);

        // Para que no se acumulen las transformaciones a los demas atributos
        transformacion.setToIdentity();
        g2d.setTransform(transformacion);

        //Fuente
        Font fuente;
        fuente = new Font(sfuente, Font.BOLD | Font.ITALIC, 45);
        g2d.setFont(fuente);
        g2d.drawString("Hola", 30, 220);

        Map atributosTexto = fuente.getAttributes();
        atributosTexto.put(TextAttribute.UNDERLINE, TextAttribute.UNDERLINE_ON);
        g2d.setFont(new Font(atributosTexto));
        g2d.drawString("H", 30, 260);

        atributosTexto.put(TextAttribute.SUPERSCRIPT, TextAttribute.SUPERSCRIPT_SUB);
        atributosTexto.put(TextAttribute.UNDERLINE, false);
        g2d.setFont(new Font(atributosTexto));
        g2d.drawString("2", 55, 260);

        atributosTexto.put(TextAttribute.SUPERSCRIPT, false);
        atributosTexto.put(TextAttribute.UNDERLINE, TextAttribute.UNDERLINE_ON);
        g2d.setFont(new Font(atributosTexto));
        g2d.drawString("O", 75, 260);

        //Renderización
        RenderingHints render;
        g2d.draw(new Ellipse2D.Float(40, 350, 510, 50)); //Elipse sin antialiasing
        render = new RenderingHints(RenderingHints.KEY_ANTIALIASING,
                RenderingHints.VALUE_ANTIALIAS_ON);
        g2d.setRenderingHints(render);
        g2d.draw(new Ellipse2D.Float(40, 450, 510, 50)); //Elipse con antialiasing
        g2d.drawString("Hola", 30, 170); //Texto con antialiasing

        //Recorte
        if (!ventanaClipActiva) {
            Shape clipArea;
            clipArea = new Ellipse2D.Float(100, 100, 500, 500);
            g2d.setClip(clipArea);

            g2d.draw(clipArea);
        }
    }

    private Shape getSelectedShape(Point2D p) {
        for (Shape s : vShape) {
            if (s.contains(p)) {
                return s;
            }
        }
        return null;
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        mover = new javax.swing.JCheckBox();
        relleno = new javax.swing.JCheckBox();
        listaFuentes = new javax.swing.JComboBox(fuentesSistema);
        window_effect = new javax.swing.JCheckBox();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        addMouseMotionListener(new java.awt.event.MouseMotionAdapter() {
            public void mouseMoved(java.awt.event.MouseEvent evt) {
                formMouseMoved(evt);
            }
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

        jPanel1.setBorder(javax.swing.BorderFactory.createBevelBorder(javax.swing.border.BevelBorder.RAISED));

        mover.setText("Mover");
        mover.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                moverActionPerformed(evt);
            }
        });
        jPanel1.add(mover);

        relleno.setText("Relleno");
        relleno.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                rellenoActionPerformed(evt);
            }
        });
        jPanel1.add(relleno);

        listaFuentes.setModel(new DefaultComboBoxModel(fuentesSistema));
        listaFuentes.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                listaFuentesActionPerformed(evt);
            }
        });
        jPanel1.add(listaFuentes);

        window_effect.setText("Efecto Ventana");
        window_effect.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                window_effectActionPerformed(evt);
            }
        });
        jPanel1.add(window_effect);

        getContentPane().add(jPanel1, java.awt.BorderLayout.PAGE_END);

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void formMousePressed(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_formMousePressed
        pAux = evt.getPoint();
        if (editar) {
            rectangulo = (Rectangle) this.getSelectedShape(pAux);
        } else {
            rectangulo = new Rectangle(pAux);
            vShape.add(rectangulo);
        }

    }//GEN-LAST:event_formMousePressed

    private void formMouseDragged(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_formMouseDragged
        if (editar) {
            if (rectangulo != null) {
                rectangulo.setLocation(evt.getPoint());
            }
        } else {
            rectangulo.setFrameFromDiagonal(pAux, evt.getPoint());
        }
        this.repaint();
    }//GEN-LAST:event_formMouseDragged

    private void formMouseReleased(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_formMouseReleased
        this.formMouseDragged(evt);
    }//GEN-LAST:event_formMouseReleased

    private void moverActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_moverActionPerformed
        editar = !editar;
    }//GEN-LAST:event_moverActionPerformed

    private void rellenoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_rellenoActionPerformed
        fill = !fill;
    }//GEN-LAST:event_rellenoActionPerformed

    private void window_effectActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_window_effectActionPerformed
        ventanaClipActiva = !ventanaClipActiva;
    }//GEN-LAST:event_window_effectActionPerformed

    private void formMouseMoved(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_formMouseMoved
        if (ventanaClipActiva) {
            Point corner = evt.getPoint();
            corner.translate((int) clipArea.getWidth() / 2,
                    (int) clipArea.getHeight() / 2);
            clipArea.setFrameFromCenter(evt.getPoint(), corner);
            this.repaint();
        }
    }//GEN-LAST:event_formMouseMoved

    private void listaFuentesActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_listaFuentesActionPerformed
        sfuente = (String)listaFuentes.getSelectedItem();
        this.repaint();
    }//GEN-LAST:event_listaFuentesActionPerformed


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JPanel jPanel1;
    private javax.swing.JComboBox<String> listaFuentes;
    private javax.swing.JCheckBox mover;
    private javax.swing.JCheckBox relleno;
    private javax.swing.JCheckBox window_effect;
    // End of variables declaration//GEN-END:variables
}
