/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package sm.aas.imagen;

import java.awt.Color;
import java.awt.image.BufferedImage;
import java.awt.image.WritableRaster;
import sm.image.BufferedImageOpAdapter;

/**
 *
 * @author adrian
 */
public class BordesOp extends BufferedImageOpAdapter {
    int umbral;
    Color color;
    
    public BordesOp(int umbral, Color color){
        this.umbral = umbral;
        this.color = color;
    }

    @Override
    public BufferedImage filter(BufferedImage src, BufferedImage dest) {
        if (src == null) {
            throw new NullPointerException("src image is null");
        }
        if(src == dest){
            throw new NullPointerException("src image can't be equal to dest");
        }
        if (dest == null) {
            dest = createCompatibleDestImage(src, null);
        }
        WritableRaster srcRaster = src.getRaster();
        WritableRaster destRaster = dest.getRaster();
        int[] pixelComp = new int[srcRaster.getNumBands()];
        int[] pixelCompIzq = new int[srcRaster.getNumBands()];
        int[] pixelCompTop = new int[srcRaster.getNumBands()];
        int[] pixelCompDest = new int[srcRaster.getNumBands()];

        for (int x = 1; x < src.getWidth(); x++) {
            for (int y = 1; y < src.getHeight(); y++) {
                srcRaster.getPixel(x, y, pixelComp);
                srcRaster.getPixel(x-1, y, pixelCompIzq);
                srcRaster.getPixel(x, y-1, pixelCompTop);
                
                int nivelGris = (int) ((pixelComp[0]+pixelComp[1]+pixelComp[2])/3);
                int nivelGrisIzq = (int) ((pixelCompIzq[0]+pixelCompIzq[1]+pixelCompIzq[2])/3);
                int nivelGrisTop = (int) ((pixelCompTop[0]+pixelCompTop[1]+pixelCompTop[2])/3);
                
                int gradoFrontera = Math.max(Math.abs(nivelGris-nivelGrisIzq), Math.abs(nivelGris-nivelGrisTop));
                
                //Implementacion necesaria para el filter
                if(gradoFrontera >= umbral){
                    pixelCompDest[0] = color.getRed();
                    pixelCompDest[1] = color.getGreen();
                    pixelCompDest[2] = color.getBlue();
                }
                else{
                    for(int i = 0; i<srcRaster.getNumBands(); i++){
                        pixelCompDest[i] = nivelGris;
                    }
                }
                
                destRaster.setPixel(x, y, pixelCompDest);
            }

        }
        return dest;
    }
    
}
