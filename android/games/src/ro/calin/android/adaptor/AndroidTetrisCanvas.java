package ro.calin.android.adaptor;

import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.util.Log;
import ro.calin.game.tetris.TetrisCanvas;

/**
 * Created with IntelliJ IDEA.
 * User: calin
 * Date: 24.02.2013
 * Time: 17:01
 * To change this template use File | Settings | File Templates.
 */
public class AndroidTetrisCanvas implements TetrisCanvas {
    public static int BRICK_SIDE_SIZE = 50;

    private final Paint paint;
    private final Canvas canvas;

    public AndroidTetrisCanvas(Bitmap frameBuffer) {
        this.paint = new Paint();
        this.canvas = new Canvas(frameBuffer);
    }

    private void drawRect(int x, int y, int width, int height, int color) {
        paint.setColor(color);
        paint.setStyle(Paint.Style.FILL);
        canvas.drawRect(x, y, x + width - 1, y + height - 1, paint);
    }

    private void clearScreen(int color) {
        canvas.drawRGB((color & 0xff0000) >> 16, (color & 0xff00) >> 8,
                (color & 0xff));
    }

    @Override
    public void drawScore(int score) {
        //To change body of implemented methods use File | Settings | File Templates.
    }

    @Override
    public void drawLevel(int level) {
        //To change body of implemented methods use File | Settings | File Templates.
    }

    @Override
    public void drawPlayArea() {
        paint.setColor(0xffffffff);
        paint.setStyle(Paint.Style.STROKE);

        int x1 = 10;
        int y1 = canvas.getHeight() - 11 - BRICK_SIDE_SIZE * Const.PLAY_AREA_HEIGHT + 1;
        int x2 = 10 + BRICK_SIDE_SIZE * Const.PLAY_AREA_WIDTH - 1;
        int y2 = canvas.getHeight() - 11;

//        canvas.drawRect(x1, y1, x2, y2, paint);
    }

    @Override
    public void drawNextPieceArea() {
        paint.setColor(0xffffffff);
        paint.setStyle(Paint.Style.STROKE);

        int x1 = canvas.getWidth() - (55 + BRICK_SIDE_SIZE * Const.NEXT_PIECE_AREA_WIDTH);
        int y1 = canvas.getHeight() - (55 + BRICK_SIDE_SIZE * Const.NEXT_PIECE_AREA_HEIGHT);
        int x2 = canvas.getWidth() - 55;
        int y2 = canvas.getHeight() - 55;

        Log.d("TTT", "" + x1 + ", " + y1 + ", " + x2 + ", " + y2);

        canvas.drawRect(x1, y1, x2, y2, paint);
    }

    @Override
    public void clearRegionInPlayArea(int x, int y, int width, int height) {
        //To change body of implemented methods use File | Settings | File Templates.
    }

    @Override
    public void clearRegionInNextPieceArea(int x, int y, int width, int height) {
        //To change body of implemented methods use File | Settings | File Templates.
    }

    @Override
    public void drawBrickInPlayArea(int x, int y) {
//        clearScreen(0xff000000);
//        drawRect(x * BRICK_SIDE_SIZE, y * BRICK_SIDE_SIZE, BRICK_SIDE_SIZE, BRICK_SIDE_SIZE, 0xffffffff);
    }

    @Override
    public void drawBrickInNextPieceArea(int x, int y) {
        //To change body of implemented methods use File | Settings | File Templates.
    }
}