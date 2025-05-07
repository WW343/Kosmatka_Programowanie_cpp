#include <vector>
#include <iostream>

class Canvas {
public:
    Canvas(size_t w, size_t h) : width(w), height(h), grid(h, std::vector<bool>(w, false)) {}
    
    void set(size_t x, size_t y) {
        if (x < width && y < height)
            grid[y][x] = true;
    }

    void print() const {
        for (const auto& row : grid) {
            for (bool c : row) {
                std::cout << (c ? "\xE2\x96\x88" : " ");
            }
            std::cout << std::endl;
        }
    }

    size_t getWidth() const {
        return width;
    }

    size_t getHeight() const {
        return height;
    }

private:
    std::vector<std::vector<bool>> grid;
    size_t width, height;
};


class Painter {
protected:
    Canvas& canvas; /* Kompozycja */
public:
    Painter(Canvas& c) : canvas(c) {}
    virtual void paint() = 0;
};


    class VerticalLinePainter: public Painter{
        int x;
        public:
        VerticalLinePainter(Canvas &c, size_t v): Painter(c), x(v){}

        void paint() override {
            for(int i = 0; i< canvas.getHeight();i++){
                canvas.set(x,i);
            }
        }
    };
    class HorizontalLinePainter : public Painter{
        int y;
        public:
            HorizontalLinePainter(Canvas &c, size_t b): Painter(c), y(b){}

        void paint() override {
            for(int i = 0; i< canvas.getWidth();i++){
                canvas.set(i,y);
            }
        }
    };

    class RectanglePainter : public Painter{
        public:
        RectanglePainter(Canvas &c):Painter(c){}

        void paint() override {
            for(int i = 0; i< canvas.getHeight();i++){
                canvas.set(0,i);
                canvas.set(canvas.getWidth()-1,i);
            }
            for(int i = 0; i< canvas.getWidth();i++){
                canvas.set(i,0);
                canvas.set(i,canvas.getHeight()-1);

            }
        }
    };


int main(){
    Canvas c(20,20);
    VerticalLinePainter vline(c,2);
    HorizontalLinePainter hline(c,2);
    RectanglePainter rect(c);

    vline.paint();
    hline.paint();
    rect.paint();

    c.print();

}