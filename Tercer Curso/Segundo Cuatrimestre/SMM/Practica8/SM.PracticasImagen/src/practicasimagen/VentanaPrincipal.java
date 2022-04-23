/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */
package practicasimagen;

import java.awt.Color;
import java.awt.Shape;
import java.awt.image.BufferedImage;
import java.io.File;
import java.util.ArrayList;
import javax.imageio.ImageIO;
import javax.swing.ComboBoxModel;
import javax.swing.DefaultComboBoxModel;
import javax.swing.JFileChooser;
import javax.swing.event.InternalFrameAdapter;
import javax.swing.SpinnerNumberModel;
import javax.swing.SpinnerModel;
import sm.aas.comboboxcolores.ColorCellRender;
import sm.aas.eventos.LienzoAdapter;
import sm.aas.eventos.LienzoEvent;
import static sm.aas.ui.Lienzo2D.Formas;

/**
 *
 * @author adri
 */
public class VentanaPrincipal extends javax.swing.JFrame {

    private boolean barraEstadoActiva = true;
    private ManejadorVentanaInterna mvi;
    private ManejadorLienzo mlienzo;
    private Formas formaActiva;

    /**
     * Creates new form VentanaPrincipal
     */
    public VentanaPrincipal() {
        initComponents();
        mvi = new ManejadorVentanaInterna();
        mlienzo = new ManejadorLienzo();
        this.setSize(1000, 1000);
        this.setTitle("Paint Basico");
        formaActiva = Formas.TRAZO_LIBRE;
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        herramientas = new javax.swing.ButtonGroup();
        barraHerramientas = new javax.swing.JToolBar();
        botonNuevoLienzo = new javax.swing.JButton();
        botonAbrir = new javax.swing.JButton();
        botonGuardar = new javax.swing.JButton();
        jSeparator1 = new javax.swing.JToolBar.Separator();
        botonVolcado = new javax.swing.JToggleButton();
        botonTrazoLibre = new javax.swing.JToggleButton();
        botonLinea = new javax.swing.JToggleButton();
        botonRectangulo = new javax.swing.JToggleButton();
        botonElipse = new javax.swing.JToggleButton();
        botonCurva = new javax.swing.JToggleButton();
        botonMover = new javax.swing.JToggleButton();
        jSeparator2 = new javax.swing.JToolBar.Separator();
        Color colores[] = {Color.BLACK, Color.RED, Color.BLUE, Color.ORANGE, Color.YELLOW, Color.GREEN};
        seleccionColor = new javax.swing.JComboBox<>(colores);
        jSeparator3 = new javax.swing.JToolBar.Separator();
        SpinnerModel valor = new SpinnerNumberModel(1,1,20,1);
        grosorSpinner = new javax.swing.JSpinner(valor);
        botonRelleno = new javax.swing.JToggleButton();
        botonTransparencia = new javax.swing.JToggleButton();
        botonAlisado = new javax.swing.JToggleButton();
        listaFiguras = new javax.swing.JComboBox<>();
        jPanel5 = new javax.swing.JPanel();
        jPanel6 = new javax.swing.JPanel();
        labelEstado = new javax.swing.JLabel();
        escritorio = new javax.swing.JDesktopPane();
        barraMenu = new javax.swing.JMenuBar();
        menuArchivo = new javax.swing.JMenu();
        menuNuevo = new javax.swing.JMenuItem();
        menuAbrir = new javax.swing.JMenuItem();
        menuGuardar = new javax.swing.JMenuItem();
        menuEdicion = new javax.swing.JMenu();
        menuVerBarraEstado = new javax.swing.JMenuItem();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        barraHerramientas.setRollover(true);

        botonNuevoLienzo.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iconos/nuevo.png"))); // NOI18N
        botonNuevoLienzo.setToolTipText("Abre una nueva ventana");
        botonNuevoLienzo.setFocusable(false);
        botonNuevoLienzo.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        botonNuevoLienzo.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        botonNuevoLienzo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botonNuevoLienzoActionPerformed(evt);
            }
        });
        barraHerramientas.add(botonNuevoLienzo);

        botonAbrir.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iconos/abrir.png"))); // NOI18N
        botonAbrir.setToolTipText("Abrir una ventana a partir de una imagen");
        botonAbrir.setFocusable(false);
        botonAbrir.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        botonAbrir.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        botonAbrir.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botonAbrirActionPerformed(evt);
            }
        });
        barraHerramientas.add(botonAbrir);

        botonGuardar.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iconos/guardar.png"))); // NOI18N
        botonGuardar.setToolTipText("Guardar la ventana actual en un archivo");
        botonGuardar.setFocusable(false);
        botonGuardar.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        botonGuardar.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        botonGuardar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botonGuardarActionPerformed(evt);
            }
        });
        barraHerramientas.add(botonGuardar);
        barraHerramientas.add(jSeparator1);

        botonVolcado.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iconos/icons8-rodillo-24.png"))); // NOI18N
        botonVolcado.setFocusable(false);
        botonVolcado.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        botonVolcado.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        botonVolcado.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botonVolcadoActionPerformed(evt);
            }
        });
        barraHerramientas.add(botonVolcado);

        herramientas.add(botonTrazoLibre);
        botonTrazoLibre.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iconos/trazo.png"))); // NOI18N
        botonTrazoLibre.setSelected(true);
        botonTrazoLibre.setToolTipText("Trazo libre");
        botonTrazoLibre.setFocusable(false);
        botonTrazoLibre.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        botonTrazoLibre.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        botonTrazoLibre.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botonTrazoLibreActionPerformed(evt);
            }
        });
        barraHerramientas.add(botonTrazoLibre);

        herramientas.add(botonLinea);
        botonLinea.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iconos/linea.png"))); // NOI18N
        botonLinea.setToolTipText("Linea");
        botonLinea.setFocusable(false);
        botonLinea.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        botonLinea.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        botonLinea.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botonLineaActionPerformed(evt);
            }
        });
        barraHerramientas.add(botonLinea);

        herramientas.add(botonRectangulo);
        botonRectangulo.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iconos/rectangulo.png"))); // NOI18N
        botonRectangulo.setToolTipText("Rectángulo");
        botonRectangulo.setFocusable(false);
        botonRectangulo.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        botonRectangulo.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        botonRectangulo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botonRectanguloActionPerformed(evt);
            }
        });
        barraHerramientas.add(botonRectangulo);

        herramientas.add(botonElipse);
        botonElipse.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iconos/elipse.png"))); // NOI18N
        botonElipse.setToolTipText("Elipse");
        botonElipse.setFocusable(false);
        botonElipse.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        botonElipse.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        botonElipse.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botonElipseActionPerformed(evt);
            }
        });
        barraHerramientas.add(botonElipse);

        herramientas.add(botonCurva);
        botonCurva.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iconos/curva.png"))); // NOI18N
        botonCurva.setToolTipText("Curva con tres puntos");
        botonCurva.setFocusable(false);
        botonCurva.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        botonCurva.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        botonCurva.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botonCurvaActionPerformed(evt);
            }
        });
        barraHerramientas.add(botonCurva);

        botonMover.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iconos/seleccion.png"))); // NOI18N
        botonMover.setToolTipText("Activar/Desactivar desplazamiento de las figuras");
        botonMover.setFocusable(false);
        botonMover.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        botonMover.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        botonMover.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botonMoverActionPerformed(evt);
            }
        });
        barraHerramientas.add(botonMover);
        barraHerramientas.add(jSeparator2);

        seleccionColor.setToolTipText("Selección de color");
        seleccionColor.setRenderer(new ColorCellRender());
        seleccionColor.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                seleccionColorActionPerformed(evt);
            }
        });
        barraHerramientas.add(seleccionColor);
        barraHerramientas.add(jSeparator3);

        grosorSpinner.addChangeListener(new javax.swing.event.ChangeListener() {
            public void stateChanged(javax.swing.event.ChangeEvent evt) {
                grosorSpinnerStateChanged(evt);
            }
        });
        barraHerramientas.add(grosorSpinner);

        botonRelleno.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iconos/rellenar.png"))); // NOI18N
        botonRelleno.setToolTipText("Activar/Desactivar rellenado de figuras");
        botonRelleno.setFocusable(false);
        botonRelleno.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        botonRelleno.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        botonRelleno.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botonRellenoActionPerformed(evt);
            }
        });
        barraHerramientas.add(botonRelleno);

        botonTransparencia.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iconos/transparencia.png"))); // NOI18N
        botonTransparencia.setToolTipText("Activar/Desactivar transparencia en las figuras");
        botonTransparencia.setFocusable(false);
        botonTransparencia.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        botonTransparencia.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        botonTransparencia.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botonTransparenciaActionPerformed(evt);
            }
        });
        barraHerramientas.add(botonTransparencia);

        botonAlisado.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iconos/alisar.png"))); // NOI18N
        botonAlisado.setToolTipText("Activar/Desactivar alisado");
        botonAlisado.setFocusable(false);
        botonAlisado.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        botonAlisado.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        botonAlisado.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botonAlisadoActionPerformed(evt);
            }
        });
        barraHerramientas.add(botonAlisado);
        barraHerramientas.add(listaFiguras);

        getContentPane().add(barraHerramientas, java.awt.BorderLayout.PAGE_START);

        jPanel5.setLayout(new java.awt.BorderLayout());

        jPanel6.setBorder(javax.swing.BorderFactory.createEtchedBorder());
        jPanel6.setLayout(new java.awt.BorderLayout());

        labelEstado.setText("Barra de estado");
        jPanel6.add(labelEstado, java.awt.BorderLayout.CENTER);

        jPanel5.add(jPanel6, java.awt.BorderLayout.CENTER);

        getContentPane().add(jPanel5, java.awt.BorderLayout.PAGE_END);
        getContentPane().add(escritorio, java.awt.BorderLayout.CENTER);

        menuArchivo.setText("Archivo");

        menuNuevo.setAccelerator(javax.swing.KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_N, java.awt.event.InputEvent.CTRL_DOWN_MASK));
        menuNuevo.setText("Nuevo");
        menuNuevo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                menuNuevoActionPerformed(evt);
            }
        });
        menuArchivo.add(menuNuevo);

        menuAbrir.setAccelerator(javax.swing.KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_O, java.awt.event.InputEvent.CTRL_DOWN_MASK));
        menuAbrir.setText("Abrir");
        menuAbrir.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                menuAbrirActionPerformed(evt);
            }
        });
        menuArchivo.add(menuAbrir);

        menuGuardar.setAccelerator(javax.swing.KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_S, java.awt.event.InputEvent.CTRL_DOWN_MASK));
        menuGuardar.setText("Guardar");
        menuGuardar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                menuGuardarActionPerformed(evt);
            }
        });
        menuArchivo.add(menuGuardar);

        barraMenu.add(menuArchivo);

        menuEdicion.setText("Ver");

        menuVerBarraEstado.setAccelerator(javax.swing.KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_V, java.awt.event.InputEvent.ALT_DOWN_MASK | java.awt.event.InputEvent.CTRL_DOWN_MASK));
        menuVerBarraEstado.setText("Ver barra de estado");
        menuVerBarraEstado.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                menuVerBarraEstadoActionPerformed(evt);
            }
        });
        menuEdicion.add(menuVerBarraEstado);

        barraMenu.add(menuEdicion);

        setJMenuBar(barraMenu);

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void botonTrazoLibreActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botonTrazoLibreActionPerformed
        VentanaInterna vi;
        vi = (VentanaInterna) escritorio.getSelectedFrame();
        if (vi != null) {
            formaActiva = Formas.TRAZO_LIBRE;
            vi.getLienzo2D().setFormaActiva(formaActiva);
        }
        if (barraEstadoActiva)
            labelEstado.setText("Trazo libre");
    }//GEN-LAST:event_botonTrazoLibreActionPerformed

    private void botonLineaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botonLineaActionPerformed
        VentanaInterna vi;
        vi = (VentanaInterna) escritorio.getSelectedFrame();
        if (vi != null) {
            formaActiva = Formas.LINEA;
            vi.getLienzo2D().setFormaActiva(formaActiva);
        }
        if (barraEstadoActiva)
            labelEstado.setText("Linea");
    }//GEN-LAST:event_botonLineaActionPerformed

    private void botonRectanguloActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botonRectanguloActionPerformed
        VentanaInterna vi;
        vi = (VentanaInterna) escritorio.getSelectedFrame();
        if (vi != null) {
            formaActiva = Formas.RECTANGULO;
            vi.getLienzo2D().setFormaActiva(formaActiva);
        }
        if (barraEstadoActiva)
            labelEstado.setText("Rectangulo");
    }//GEN-LAST:event_botonRectanguloActionPerformed

    private void botonElipseActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botonElipseActionPerformed
        VentanaInterna vi;
        vi = (VentanaInterna) escritorio.getSelectedFrame();
        if (vi != null) {
            formaActiva = Formas.ELIPSE;
            vi.getLienzo2D().setFormaActiva(formaActiva);
        }
        if (barraEstadoActiva)
            labelEstado.setText("Elipse");
    }//GEN-LAST:event_botonElipseActionPerformed

    private void grosorSpinnerStateChanged(javax.swing.event.ChangeEvent evt) {//GEN-FIRST:event_grosorSpinnerStateChanged
        VentanaInterna vi;
        vi = (VentanaInterna) escritorio.getSelectedFrame();
        vi.getLienzo2D().setGrosor((int) grosorSpinner.getValue());
        this.repaint();
    }//GEN-LAST:event_grosorSpinnerStateChanged

    private void botonCurvaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botonCurvaActionPerformed
        VentanaInterna vi;
        vi = (VentanaInterna) escritorio.getSelectedFrame();
        if (vi != null) {
            formaActiva = Formas.QUAD_CURVE;
            vi.getLienzo2D().setFormaActiva(formaActiva);
        }
        if (barraEstadoActiva)
            labelEstado.setText("Curva");
    }//GEN-LAST:event_botonCurvaActionPerformed

    private void menuVerBarraEstadoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_menuVerBarraEstadoActionPerformed
        barraEstadoActiva = !barraEstadoActiva;
        labelEstado.setText(" ");
    }//GEN-LAST:event_menuVerBarraEstadoActionPerformed

    private void menuGuardarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_menuGuardarActionPerformed
        VentanaInterna vi = (VentanaInterna) escritorio.getSelectedFrame();
        if (vi != null) {
            BufferedImage img = vi.getLienzo2D().getImage(true);
            if (img != null) {
                JFileChooser dlg = new JFileChooser();
                int resp = dlg.showSaveDialog(this);
                if (resp == JFileChooser.APPROVE_OPTION) {
                    try {
                        File f = dlg.getSelectedFile();
                        ImageIO.write(img, "jpg", f);
                        vi.setTitle(f.getName());
                    } catch (Exception ex) {
                        System.err.println("Error al guardar la imagen");
                    }
                }
            }
        }
    }//GEN-LAST:event_menuGuardarActionPerformed

    private void menuAbrirActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_menuAbrirActionPerformed
        JFileChooser dlg = new JFileChooser();
        int resp = dlg.showOpenDialog(this);
        if (resp == JFileChooser.APPROVE_OPTION) {
            try {
                File f = dlg.getSelectedFile();
                BufferedImage img = ImageIO.read(f);
                VentanaInterna vi = new VentanaInterna();
                vi.getLienzo2D().setImage(img);
                this.escritorio.add(vi);
                vi.setTitle(f.getName());
                vi.setVisible(true);
                vi.addInternalFrameListener(mvi);
                vi.getLienzo2D().addLienzoListener(mlienzo);
            } catch (Exception ex) {
                System.err.println("Error al leer la imagen");
            }
        }
    }//GEN-LAST:event_menuAbrirActionPerformed

    private void menuNuevoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_menuNuevoActionPerformed
        VentanaInterna vi = new VentanaInterna();
        escritorio.add(vi);
        vi.setVisible(true);
        vi.addInternalFrameListener(mvi);
        vi.getLienzo2D().addLienzoListener(mlienzo);
        BufferedImage img;
        img = new BufferedImage(300, 300, BufferedImage.TYPE_INT_RGB);
        vi.getLienzo2D().setImage(img);
    }//GEN-LAST:event_menuNuevoActionPerformed

    private void botonNuevoLienzoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botonNuevoLienzoActionPerformed
        VentanaInterna vi = new VentanaInterna();
        escritorio.add(vi);
        vi.setVisible(true);
        vi.addInternalFrameListener(mvi);
        vi.getLienzo2D().addLienzoListener(mlienzo);
        BufferedImage img;
        img = new BufferedImage(300, 300, BufferedImage.TYPE_INT_RGB);
        vi.getLienzo2D().setImage(img);
        
    }//GEN-LAST:event_botonNuevoLienzoActionPerformed

    private void botonAbrirActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botonAbrirActionPerformed
        JFileChooser dlg = new JFileChooser();
        int resp = dlg.showOpenDialog(this);
        if (resp == JFileChooser.APPROVE_OPTION) {
            try {
                File f = dlg.getSelectedFile();
                BufferedImage img = ImageIO.read(f);
                VentanaInterna vi = new VentanaInterna();
                vi.getLienzo2D().setImage(img);
                this.escritorio.add(vi);
                vi.setTitle(f.getName());
                vi.setVisible(true);
                vi.addInternalFrameListener(mvi);
                vi.getLienzo2D().addLienzoListener(mlienzo);
            } catch (Exception ex) {
                System.err.println("Error al leer la imagen");
            }
        }
    }//GEN-LAST:event_botonAbrirActionPerformed

    private void botonGuardarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botonGuardarActionPerformed
        VentanaInterna vi = (VentanaInterna) escritorio.getSelectedFrame();
        if (vi != null) {
            BufferedImage img = vi.getLienzo2D().getImage(true);
            if (img != null) {
                JFileChooser dlg = new JFileChooser();
                int resp = dlg.showSaveDialog(this);
                if (resp == JFileChooser.APPROVE_OPTION) {
                    try {
                        File f = dlg.getSelectedFile();
                        ImageIO.write(img, "jpg", f);
                        vi.setTitle(f.getName());
                    } catch (Exception ex) {
                        System.err.println("Error al guardar la imagen");
                    }
                }
            }
        }
    }//GEN-LAST:event_botonGuardarActionPerformed

    private void botonMoverActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botonMoverActionPerformed
        VentanaInterna vi;
        vi = (VentanaInterna) escritorio.getSelectedFrame();
        vi.getLienzo2D().setMover(!vi.getLienzo2D().isMover());
        this.repaint();
    }//GEN-LAST:event_botonMoverActionPerformed

    private void botonRellenoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botonRellenoActionPerformed
        VentanaInterna vi;
        vi = (VentanaInterna) escritorio.getSelectedFrame();
        vi.getLienzo2D().setRelleno(!vi.getLienzo2D().isRelleno());
        this.repaint();
    }//GEN-LAST:event_botonRellenoActionPerformed

    private void botonTransparenciaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botonTransparenciaActionPerformed
        VentanaInterna vi;
        vi = (VentanaInterna) escritorio.getSelectedFrame();
        vi.getLienzo2D().setTrans_activa(!vi.getLienzo2D().isTrans_activa());
        this.repaint();
    }//GEN-LAST:event_botonTransparenciaActionPerformed

    private void botonAlisadoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botonAlisadoActionPerformed
        VentanaInterna vi;
        vi = (VentanaInterna) escritorio.getSelectedFrame();
        vi.getLienzo2D().setAlisado(!vi.getLienzo2D().isAlisado());
        this.repaint();
    }//GEN-LAST:event_botonAlisadoActionPerformed

    private void botonVolcadoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botonVolcadoActionPerformed
         VentanaInterna vi;
         vi = (VentanaInterna) escritorio.getSelectedFrame();
         vi.getLienzo2D().setVolcado(!vi.getLienzo2D().isVolcado());
    }//GEN-LAST:event_botonVolcadoActionPerformed

    private void seleccionColorActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_seleccionColorActionPerformed
        Color colorSelecionado = (Color)seleccionColor.getSelectedItem();
        VentanaInterna vi;
        vi = (VentanaInterna) escritorio.getSelectedFrame();
        vi.getLienzo2D().setColor(colorSelecionado);
        this.repaint();
    }//GEN-LAST:event_seleccionColorActionPerformed

    private class ManejadorVentanaInterna extends InternalFrameAdapter {

        public void internalFrameActivated(javax.swing.event.InternalFrameEvent evt) {
            VentanaInterna vi = (VentanaInterna) evt.getInternalFrame();
            
            botonRelleno.setSelected(vi.getLienzo2D().isRelleno());
            botonTransparencia.setSelected(vi.getLienzo2D().isTrans_activa());
            botonAlisado.setSelected(vi.getLienzo2D().isAlisado());
            botonMover.setSelected(vi.getLienzo2D().isMover());
            grosorSpinner.setValue((int) vi.getLienzo2D().getGrosor());
            botonVolcado.setSelected(vi.getLienzo2D().isVolcado());
            
            switch(formaActiva){
                case TRAZO_LIBRE:
                    botonTrazoLibre.setSelected(true);
                break;
                case LINEA:
                    botonLinea.setSelected(true);
                break;
                case RECTANGULO:
                    botonRectangulo.setSelected(true);
                break;
                case ELIPSE:
                    botonElipse.setSelected(true);
                break;
                case QUAD_CURVE:
                    botonCurva.setSelected(true);
                break;
            }
        }
    }
    
    private class ManejadorLienzo extends LienzoAdapter{
        public void shapeAdded(LienzoEvent evt){
            listaFiguras.addItem(evt.getForma());
        }
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JToolBar barraHerramientas;
    private javax.swing.JMenuBar barraMenu;
    private javax.swing.JButton botonAbrir;
    private javax.swing.JToggleButton botonAlisado;
    private javax.swing.JToggleButton botonCurva;
    private javax.swing.JToggleButton botonElipse;
    private javax.swing.JButton botonGuardar;
    private javax.swing.JToggleButton botonLinea;
    private javax.swing.JToggleButton botonMover;
    private javax.swing.JButton botonNuevoLienzo;
    private javax.swing.JToggleButton botonRectangulo;
    private javax.swing.JToggleButton botonRelleno;
    private javax.swing.JToggleButton botonTransparencia;
    private javax.swing.JToggleButton botonTrazoLibre;
    private javax.swing.JToggleButton botonVolcado;
    private javax.swing.JDesktopPane escritorio;
    private javax.swing.JSpinner grosorSpinner;
    private javax.swing.ButtonGroup herramientas;
    private javax.swing.JPanel jPanel5;
    private javax.swing.JPanel jPanel6;
    private javax.swing.JToolBar.Separator jSeparator1;
    private javax.swing.JToolBar.Separator jSeparator2;
    private javax.swing.JToolBar.Separator jSeparator3;
    private javax.swing.JLabel labelEstado;
    private javax.swing.JComboBox<Shape> listaFiguras;
    private javax.swing.JMenuItem menuAbrir;
    private javax.swing.JMenu menuArchivo;
    private javax.swing.JMenu menuEdicion;
    private javax.swing.JMenuItem menuGuardar;
    private javax.swing.JMenuItem menuNuevo;
    private javax.swing.JMenuItem menuVerBarraEstado;
    private javax.swing.JComboBox<Color> seleccionColor;
    // End of variables declaration//GEN-END:variables
}
