void setup() {
  size(800, 400);
  stroke(255);
  background(51);
  color from = color(255, 0, 0);
  color to = color(0, 0, 255);
  fill(from);
  int x=10;
  int y=20;
  rect(x, y, y, y*3);
  for (int i=0; i<66; i++) {
    color col=lerpColor(from, to, map(i, 0, 66, 0, 1));
    fill(col);
    x+=20;
    rect(x, y, y, y*3);
    print(" matrix.Color(",int(red(col)),",", int(green(col)),",", int(blue(col)),"),");
    println();
  }
}
void draw() {
}
//color interA = lerpColor(from, to, .33);
//color interB = lerpColor(from, to, .66);
