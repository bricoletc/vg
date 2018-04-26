#ifndef VG_SIMULATOR_HPP_INCLUDED
#define VG_SIMULATOR_HPP_INCLUDED

#include <vector>
#include <cairo.h>
#include <cairo-svg.h>
#include <iostream>
#include <chrono>
#include <ctime>
#include "xg.hpp"
#include "packer.hpp"
#include "alignment.hpp"
#include "path.hpp"
#include "position.hpp"
#include "json2pb.h"

namespace vg {

using namespace std;

class Viz {
public:
    Viz(void) { }
    ~Viz(void) { close(); }
    Viz(xg::XG* x, vector<Packer>* p, const string& o, int w, int h, bool c);
    void init(xg::XG* x, vector<Packer>* p, const string& o, int w, int h, bool c);
    void draw(void);
    void draw_graph(void);
    void close(void);
private:
    double node_offset(id_t id);
    void set_hash_color(const string& str);
    xg::XG* xgidx = nullptr;
    vector<Packer>* packs = nullptr;
    string outfile;
    cairo_surface_t *surface = nullptr;
	cairo_t *cr = nullptr;
    bool output_png = false;
    bool output_svg = false;
    bool show_cnv = true;
    int image_width = 0;
    int image_height = 0;
    int left_border = 0;
    int top_border = 0;
};

tuple<double, double, double> hash_to_rgb(const string& str, double min_sum);

}

#endif
