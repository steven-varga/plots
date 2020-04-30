
# Charts for Modern C++
is a high performance header only plotting library supporting major linear algebra systems, the STL and STL like objects, and currently Scalable Graphics Format or SVG backend with no external dependency. In addition to SVG the library supports [wxWidgets][100] [canvas][101] and when linked against [Cairo Graphics Library][102]

- SVG :
	- built in, header only, no dependencies
- Cairo:
	- PDF
	- PostScript
	- PNG
	- JPEG
	- TIFF
- wxWidget:
	- PDF
	- PostScript
	- PNG
	- JPEG
	- TIFF
	- SVG

# Charts

- [line][213], [scatter][209] bar plots
- [histograms][202]
- [probability][204]
- bode plots
- [contour plot][203]
- [carpet plot][205]
- [heat map][206]
- [nyquist plot][207]
- [QQ plot][208]
- [spaghetti plot][210]
- [surface plot][2011]
- [vector field][212]

### Supported Objects
- Armadillo Linear algebra for C++
- Eigen
- Blitz
- `T[N][M][...]`, `T*`, `std::vector<T>`, `std::array<T,N>`

### Prerequisites  
C++17 compiler is the only requirement, in addition serial or parallel HDF5 is supported through [H5CPP](http://h5cpp.org) header only seamless persistence for HPC by the same author, and other formats if linked against Cairo Graphics or used with wxWidgets canvases.


[100]: https://www.wxwidgets.org/
[101]: https://wiki.wxwidgets.org/WxDC
[102]: https://www.cairographics.org/documentation/

[202]: https://en.wikipedia.org/wiki/Histogram
[203]: https://en.wikipedia.org/wiki/Contour_line
[204]: https://en.wikipedia.org/wiki/Probability_plot
[205]: https://en.wikipedia.org/wiki/Carpet_plot
[206]: https://en.wikipedia.org/wiki/Heat_map
[207]: https://en.wikipedia.org/wiki/Nyquist_stability_criterion#Nyquist_plot
[208]: https://en.wikipedia.org/wiki/Q%E2%80%93Q_plot
[209]: https://en.wikipedia.org/wiki/Scatter_plot
[210]: https://en.wikipedia.org/wiki/Spaghetti_plot
[211]: https://en.wikipedia.org/wiki/Plot_(graphics)#/media/File:Surface-plot.jpg
[212]: https://en.wikipedia.org/wiki/Plot_(graphics)#/media/File:Surface-plot.jpg
[213]: https://en.wikipedia.org/wiki/Line_chart
