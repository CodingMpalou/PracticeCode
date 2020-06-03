#ifndef RUST_CLASS_RUSTWORLD_H
#define RUST_CLASS_RUSTWORLD_H

class RustWorld {
    public:
        RustWorld();
        RustWorld(int XDIM, int YDIM);

        int getXDIM() const;
        void setXDIM(int XDIM);
        int getYDIM() const;
        void setYDIM(int YDIM);

    private:
        int XDIM;
        int YDIM;
};

#endif
