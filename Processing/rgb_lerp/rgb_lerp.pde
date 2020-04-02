void setup() {
  size(750, 200);
  stroke(255);
  background(51);
  drawHSB();
  //drawRGB();


}
void draw() {
}

void drawRGB(){
  colorMode(RGB);

  color from = color(255, 0, 0); //starting color
  color to = color(0, 255, 0);   //mid color
  int x=10;
  int y=20;
  //fill(from);
  //rect(x, y, y, y*3);
  for (int i=0; i<32; i++) {
    
    color col=lerpColor(from, to, map(i, 0, 32, 0, 1));
    fill(col);
    rect(x, y, y, y*3);
    
    x+=10;

    //print output in RGB
    print(" matrix.Color(", int(red(col)), ",", int(green(col)), ",", int(blue(col)), "),");
    println();
  }
  color from2 = to;//mid color
  color to2 = color(0, 0, 255); //end color
  for (int i=0; i<32; i++) {
    
    color col=lerpColor(from2, to2, map(i, 0, 32, 0, 1));
    fill(col);
    rect(x, y, y, y*3);
    
    x+=10;
    
    //print output in RGB
    print(" matrix.Color(", int(red(col)), ",", int(green(col)), ",", int(blue(col)), "),");
    println();
  }
}
void drawHSB(){
  colorMode(HSB, 100);
  
  //declare initial colors
  color from = color(70, 80, 90);//blue
  color to = color(100, 100, 100);//red
  int x=10;
  int y=20;

  //do the linear interpolation over 64 entries
  for (int i=0; i<64; i++) {
   
    color col=lerpColor(from, to, map(i, 0, 64, 0, 1));
    fill(col);
    rect(x, y, y, y*3);
    
    x+=10;

    //print output in RGB
    print(" matrix.Color(", int(red(col)), ",", int(green(col)), ",", int(blue(col)), "),");
    println();
  }

}
