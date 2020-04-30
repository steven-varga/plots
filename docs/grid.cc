#include <iostream>
#include <fstream>
#include <array>

struct svg {
	svg(const std::string& filename, size_t width, size_t height,  const std::array<float,4>& margin ) 
		: width(width), height(height), margin( margin ) {
		os.open(filename, std::ios::out | std::ios::trunc);
	}
	void style(){
		os << "<svg viewBox=\"-0 0 400 200\" xmlns=\"http://www.w3.org/2000/svg\" fill=\"red\">\n";

		os << "<style>\n"
		"\tsvg.cartesian { display:flex;}\n"
		"\tsvg.cartesian > g { transform: scaleY(-1);}\n"
		"\tsvg.cartesian > g text { transform: scaleY(-1);}\n"
		"</style>\n";
	}

	void axes( ){
		float mx = -1 * margin[0]; float my = margin[1]; 
		float lx = width + mx - margin[2];
		float ly = height;

		os << "<svg x=\""<< 10 <<"\" y=\"" << -10 <<"\" stroke=\"blue\" viewBox=\"" 
			<< 0 << " " << height / -1.0  <<" " << width << " " << height << "\">\n";
		os << "<path d=\"M0," << margin[1] + margin[3] <<" L0,"
			<< ly << " M0," << ly <<" L"<< lx <<"," << ly << "\" stroke=\"red\" stroke-width=\"1.4\"/>\n";

		os << "<circle cx=\"0\" cy=\"0\" r=\"50\" stroke=\"blue\" />\n";
	}

	void scale(size_t step){
		size_t x_ = width;		size_t y_ = height;
		os << "<path d=\"";
		for (int x=step; x < width; x+=step)
			os << "M" << x <<"," << y_ << " L" << x << "," << y_ + ( x % (5*step) ? 4 : 10 ) << " ";
		for (int y=step; y<y_; y+=step)
			os << "M" << ( y % (5*step) ? -4 : -10) <<"," << y_ - y << " L" << "0" << "," << y_ - y<<" ";
		os << "\" stroke-width=\".3\" stroke=\"blue\"/>";
		os << std::endl;
	}
	void circle( float cx, float cy, float rx = 10.0 ){
		os << "<circle cx=\"" << cx << "\" cy=\"" << cy << "\" r=\"" << rx << "\"/>\n";
	}
	void	grid(size_t step){
		size_t x_ = width;		size_t y_ = height;
		circle(0,0);
		os << "<path d=\"";
		for (int x=step; x < width; x+=step)
			os << "M" << x <<"," << y_ << " L" << x << "," << y_ + ( x % (5*step) ? 4 : 10 ) << " ";
		for (int y=step; y<y_; y+=step)
			os << "M" << ( y % (5*step) ? -4 : -10) <<"," << y_ - y << " L" << "0" << "," << y_ - y<<" ";
		os << "\" stroke-width=\".3\" stroke=\"blue\"/>";
		os << std::endl;
	}

	void init(){
		os <<
			"<g fill=\"transparent\" font-size=\"10\" stroke=\"grey\" stroke-width=\"4.0\">\n"
				"<rect width=\"100%\" height=\"100%\" fill=\"blue\" opacity=\"0.1\" />\n"
				"<rect width=\"100%\" height=\"100%\" stroke-dasharray=\"10 10\" />\n"
			"</g>\n"
			"<text transform=\"rotate(-25 200 100)\" x=\"50%\" y=\"50%\" font-size=\"30\" font-weight=\"bold\" opacity=\".3\" text-anchor=\"middle\">Plotting Area...</text>\n";
	}

	void end(){
		os  << "</svg>\n";
	}

	size_t width, height;
	std::array<float,4> margin;
	std::ofstream os;
};


int main(){
	svg svg("/home/steven/test.svg", 360,180, {20.00,20.00,20,20});
	svg.style();
	svg.init();
	svg.grid( 5 );
	svg.end();
}
