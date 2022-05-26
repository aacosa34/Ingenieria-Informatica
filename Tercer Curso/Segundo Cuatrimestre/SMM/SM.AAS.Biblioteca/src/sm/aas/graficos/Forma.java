/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package sm.aas.graficos;

import java.awt.Color;
import java.awt.Composite;
import java.awt.Paint;
import java.awt.RenderingHints;
import java.awt.Stroke;

/**
 *
 * @author adrian
 */
public abstract class Forma {
    private Paint relleno;
    private Color color;
    private Stroke trazo;
    private Composite comp;
    private RenderingHints render;
    
    public Forma(Paint relleno, Color color, Stroke trazo, Composite comp){
        
    }
     
}
