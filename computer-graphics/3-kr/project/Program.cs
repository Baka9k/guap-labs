﻿using System;
using System.Windows.Forms;
using System.Drawing;
using System.Drawing.Drawing2D;


public class Draw : Form 
{

    private Point[] points = 
    {
        new Point(200, 300), new Point(300, 300), new Point(300, 250), 
        new Point(400, 325), new Point(300, 400), new Point(300, 350),
        new Point(200, 350), new Point(200, 300)
    };

    public Draw()
    {
        this.Text = "Рисуем фигуру";
        this.Size = new Size(600, 600);
        this.Paint += new PaintEventHandler(Draw_Graphics);

        this.KeyPress += new KeyPressEventHandler(keyPressHandler);

        MessageBox.Show("Нажмите:\n 1 - для поворота по часовой стрелке\n2 - для поворота против часовой " + 
            "стрелки\n3 - для переноса влево\n4 - для переноса вправо");
    }


    public void Draw_Graphics(object sender, PaintEventArgs e)
    {

        // Получаем объект Graphics через идентификатор окна
        Graphics g = Graphics.FromHwnd(this.Handle);
        // А также ширину и высоту области для рисования
        int w = ClientSize.Width;
        int h = ClientSize.Height;
        // Очистка формы с помощью закрашенного прямоугольника
        g.FillRectangle(Brushes.White, 0, 0, w, h);

        // Стрелка
        g.DrawPolygon(Pens.Green, points);

    }


    private void keyPressHandler(object sender, KeyPressEventArgs e)
    {
        if (e.KeyChar == 49) rotate("clockwise");
        if (e.KeyChar == 50) rotate("conterclockwise");
        if (e.KeyChar == 51) moveLeft();
        if (e.KeyChar == 52) moveRight();
    }


    private void moveRight()
    {
        for(int i = 0; i < points.Length; i++)
        {
            points[i].X += 10;
        }
        this.Invalidate();
    }


    private void moveLeft()
    {
        for (int i = 0; i < points.Length; i++)
        {
            points[i].X -= 10;
        }
        this.Invalidate();
    }


    private void rotate(string direction)
    {

        int rotationAngle = 15;
        if (direction == "clockwise") rotationAngle = -15;
        double rotationRadians = rotationAngle * (Math.PI / 180);

        for (int i = 0; i < points.Length; i++)
        {
            points[i].X = (int) Math.Round(
                ( points[i].X * Math.Cos(rotationRadians)) -
                ( points[i].Y * Math.Sin(rotationRadians))
            );
            points[i].Y = (int) Math.Round(
                ( points[i].X * Math.Sin(rotationRadians)) + 
                ( points[i].Y * Math.Cos(rotationRadians))
            );
        }

        this.Invalidate();

    }


    public static void Main()
    {
        Application.Run(new Draw());
    }
    
}