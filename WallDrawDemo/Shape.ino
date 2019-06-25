//蝴蝶曲线
void butterfly_curve(int xx,int yy,int lines,int x_scale,int y_scale)
//xx,yy 蝴蝶中心位置， lines 圈数，越多越复杂  x_scale，y_scale xy轴的放大比例
{
  float xa,ya,p,e;
  pen_up();
  moveto(xx,yy + y_scale  * 0.71828);
  pen_down();
  
  for(float i=0;i<6.28*lines;i+=3.14/90)
  {
          
    p=pow(sin(i/12),5);
    e=pow(2.71828,cos(i));

    xa=x_scale * sin(i) * (e - 2*cos(4*i) + p);
    ya=y_scale * cos(i) * (e - 2*cos(4*i) + p);
    line_safe(xa+xx,ya+yy); 
  }
  pen_up();
}  

//桃心曲线
void heart_curve(int xx,int yy,float x_scale,float y_scale)
//xx,yy 桃心曲线中心位置， x_scale，y_scale xy轴的放大比例
{
  float xa,ya;
  
  pen_up();
  moveto(xx,yy+y_scale * 7);
  pen_down();
  for(float i=0;i<=6.28;i+=3.14/180)
  {       
    xa=x_scale * pow(sin(i),3) * 15;
    ya=y_scale * (15*cos(i) -5*cos(2*i) - 2*cos(3*i) - cos(4*i));
    line_safe(xa+xx,ya+yy);  
  }
  pen_up();
} 

//方框1
void rectangle(float xx,float yy,float dx,float dy,float angle)
{
  float six,csx,siy,csy;
  dx/=2;
  dy/=2;

  six = sin(angle/180*3.14) * dx;
  csx = cos(angle/180*3.14) * dx;
  
  siy = sin(angle/180*3.14) * dy;
  csy = cos(angle/180*3.14) * dy;
  
  pen_up();
  line_safe(csx - siy + xx,six + csy + yy);
  pen_down();
  line_safe(xx - csx - siy,csy - six + yy);
  line_safe(xx - csx + siy,yy - csy - six);
  line_safe(csx + siy + xx,six - csy + yy);
  line_safe(csx - siy + xx,six + csy + yy);
  pen_up();
}

//方框2
void box(float xx,float yy,float dx,float dy)
{
    pen_up();
    line_safe(xx , yy);
    pen_down();
   delay(TPD);
     line_safe(xx + dx, yy);
   delay(TPD);
     line_safe(xx + dx, yy+ dy);
   delay(TPD);
     line_safe(xx , yy + dy);
   delay(TPD);
   line_safe(xx , yy);
   pen_up();

}

//圆
void circle(float xx,float yy,float radius_x,float radius_y)
{
  float rx,ry;
  float st= 3.14159 / 90; //圆分割精度
   pen_up();
   line(xx+radius_x,yy);
   pen_down();
   for(float i=0;i<6.28318;i+=st)
  {
    rx = cos(i) * radius_x;
    ry = sin(i) * radius_y;
    line(xx+rx,yy+ry);
  }
  pen_up();
}

//星
void star(float xx,float yy,float radius_r,int corner)
{
  
}
