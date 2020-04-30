## Design considerations
All objects are thin, compile time defined types with static inheritance or CRTP when needed - no virtual tables. RAII enabled resources, intuitive exception framework similar to [H5CPP error handling][401] leverage the difference between legacy and modern libraries with easy to use pythonic syntax. 

In addition to basics, this plot library requires no dependencies to produce feature rich beautiful plots to [SVG format][402]. Similarly to matching H5CPP library, it is aware of major linear algebra libraries such as [armadillo][200], [eigen][201], [blitz][202] [, and more...][203] as well as [wxWidget][102] canvases and when linked against [Cairo Graphics][102] even more. And finally, **unlike matplotlib** for C++ this plot lib is thread safe, needs no python, and fast.


### coordinate system
currently Cartesian `(0,0)` is lower left corner for objects placed on plots.

## Plots
<svg viewBox="-0 0 400 200" xmlns="http://www.w3.org/2000/svg" fill="red">
<style>
	svg.cartesian { display:flex;}
	svg.cartesian > g { transform: scaleY(-1);}
	svg.cartesian > g text { transform: scaleY(-1);}
</style>
<g fill="transparent" font-size="10" stroke="grey" stroke-width="4.0">
<rect width="100%" height="100%" fill="blue" opacity="0.1" />
<rect width="100%" height="100%" stroke-dasharray="10 10" />
</g>
<text transform="rotate(-25 200 100)" x="50%" y="50%" font-size="30" font-weight="bold" opacity=".3" text-anchor="middle">Plotting Area...</text>
</svg>
### **heatmap**
```
using namespace plot;
arma::Mat<unsigned> M = ...;
std::vector<std::string> x_axis = ...;
std::vector<std::string> y_axis = ...;

heatmap("pix/typemap.svg", M, 
	height{400}, width{600}, axis::x{x_axis}, axis::y{y_axis},
	title{"my  graph", position{150,40}, font{"Ubuntu Mono", "bold", 40}, layout::horizontal},
	footnote{"footnote", position{align::left, align::top}, 
			color::fg{0xffaabb}, color::bg{0x0}, 
			layout::vertical},
	legend{	text{"success","failure","not executed"},
			color::fg{0xff0011, 0xbbaacc, 0xaabbcc},
			position{100,10}
			});
```

```xml
<svg viewBox="0 0 400 400"  xmlns="http://www.w3.org/2000/svg">
	<g x="30" y="10" transform="matrix(1 0 1 0 10 0)">
		<path d="M20,20 L180,20 M20,50 L180,50 M20,80 L180,80" stroke="grey"/>
		<text x="145" text-anchor="middle" y="45" font-size="40" font-family="Ubuntu Mono" font-weight="bold">my  graph</text>
	</g>
	<g font-size="40" font-family="Ubuntu Mono" font-weight="bold" stroke="orange" fill="green">
		<rect x="200" y="200" width="50" height="80" transform="rotate(0 200 200) " />
		<rect x="200" y="200" width="50" height="80" transform="rotate(10 200 200) " />
		<rect x="200" y="200" width="50" height="80" transform="rotate(20 200 200) " />
		<rect x="200" y="200" width="50" height="80" transform="rotate(30 200 200) " />
		<rect x="200" y="200" width="50" height="80" transform="rotate(40 200 200) " />
	</g>
	<g  transform="translate(200,200)" text-anchor="start" font-size="10">
		<text x="0" y="0"  transform="rotate(-45 0 0)">first text</text>
		<text x="0" y="10" transform="rotate(-45 0 10)">second text</text>
		<text x="0" y="20" transform="rotate(-45 0 20)">third text</text>
		<text x="0" y="30" transform="rotate(-45 0 30)">forth text</text>
	</g>
</svg>
```


## Elements

### **text**
```cpp
words ::= const std::string& | std::vector<std::string> | (string literal [,...])
	| const char ** | const char[N] const & 
	| const std::string& | ( string literal [, string literal...])
	  
plot::text{ std::string [, ...] | std::vector<std::string>, position{...} [, font{...}] [, horizontal | vertical | angle{...} ]  }
```
an arbitrary length string elements, or vector of them displayed on a canvas at a [position](#position) with optionally specified [font](#font),  [rotate](#rotate)ion, alignment.

<svg width="400" height="200" viewBox="-0 0 400 200" xmlns="http://www.w3.org/2000/svg" fill="red">
	<g fill="transparent" font-size="10" stroke="grey" stroke-width="4.0">
		<rect width="100%" height="100%" fill="blue" opacity="0.1" />
		<rect width="100%" height="100%" stroke-dasharray="10 10" />
	</g>
	<text transform="rotate(-25 200 100)" x="50%" y="50%" font-size="30" font-weight="bold" opacity=".3" text-anchor="middle">Plotting Area</text>
	<svg x="15" y="0" stroke="blue" viewBox="-10 0 400 200">
    	<path d="M0,20 L0,180 M0,180 L360,180" stroke-width=".4"/>
<path d="M5,180 L5,184 M10,180 L10,184 M15,180 L15,184 M20,180 L20,184 M25,180 L25,190 M30,180 L30,184 M35,180 L35,184 M40,180 L40,184 M45,180 L45,184 M50,180 L50,190 M55,180 L55,184 M60,180 L60,184 M65,180 L65,184 M70,180 L70,184 M75,180 L75,190 M80,180 L80,184 M85,180 L85,184 M90,180 L90,184 M95,180 L95,184 M100,180 L100,190 M105,180 L105,184 M110,180 L110,184 M115,180 L115,184 M120,180 L120,184 M125,180 L125,190 M130,180 L130,184 M135,180 L135,184 M140,180 L140,184 M145,180 L145,184 M150,180 L150,190 M155,180 L155,184 M160,180 L160,184 M165,180 L165,184 M170,180 L170,184 M175,180 L175,190 M180,180 L180,184 M185,180 L185,184 M190,180 L190,184 M195,180 L195,184 M200,180 L200,190 M205,180 L205,184 M210,180 L210,184 M215,180 L215,184 M220,180 L220,184 M225,180 L225,190 M230,180 L230,184 M235,180 L235,184 M240,180 L240,184 M245,180 L245,184 M250,180 L250,190 M255,180 L255,184 M260,180 L260,184 M265,180 L265,184 M270,180 L270,184 M275,180 L275,190 M280,180 L280,184 M285,180 L285,184 M290,180 L290,184 M295,180 L295,184 M300,180 L300,190 M305,180 L305,184 M310,180 L310,184 M315,180 L315,184 M320,180 L320,184 M325,180 L325,190 M330,180 L330,184 M335,180 L335,184 M340,180 L340,184 M345,180 L345,184 M350,180 L350,190 M355,180 L355,184 M-4,175 L0,175 M-4,170 L0,170 M-4,165 L0,165 M-4,160 L0,160 M-10,155 L0,155 M-4,150 L0,150 M-4,145 L0,145 M-4,140 L0,140 M-4,135 L0,135 M-10,130 L0,130 M-4,125 L0,125 M-4,120 L0,120 M-4,115 L0,115 M-4,110 L0,110 M-10,105 L0,105 M-4,100 L0,100 M-4,95 L0,95 M-4,90 L0,90 M-4,85 L0,85 M-10,80 L0,80 M-4,75 L0,75 M-4,70 L0,70 M-4,65 L0,65 M-4,60 L0,60 M-10,55 L0,55 M-4,50 L0,50 M-4,45 L0,45 M-4,40 L0,40 M-4,35 L0,35 M-10,30 L0,30 M-4,25 L0,25 M-4,20 L0,20 M-4,15 L0,15 M-4,10 L0,10 M-10,5 L0,5 " stroke-width=".3" >
</svg>
</svg>


**example**: displays text within a given plot vertically, aligned to top left corner
```cpp 
using namespace plot;
histogram( ...,  
	text({"blue color","red color", ",..."}, 
		align::left, 
		position{align::left, align::top}, // controls positional alignment 
		font{"Ubuntu Mono", "normal", 17}, vertical) [, ...]);
```

### **title**
`title{"title of a plot" [, position] [, font] [, layout]}` is a specialized [text](#text) 
that prints out a single line with some attributes. It can be replaced with `text{}` element at the cost of decreased readability.

### **footprint**
`footprint{"note at the bottom of the page" [, position] [, font] [, layout]}` is a specialized [text](#text) 
that prints out a single line with some attributes by default at the bottom of the chart. 
It can be replaced with `text{...}` element at the cost of decreased readability.


### **legend**
`legend{ words, color{...}, [, marker] [, position] [, font] [, layout]}` is a specialized [text](#text) 
that prints out a set of lines with some attributes by default at the bottom of the chart.
It can be replaced with `text{...}` element at the cost of decreased readability.


### **grid**
`grid{x,y [,...] [, attributes]}` to specify grid with rank N, usually N=2 or 2D, [`attributes`](#attributes) control width, type, color, ... etc. To increase readability there are some predefined ones:

- `dot::grid{ .. }`
- `dash::grid{ .. }`
- `line::grid{ ... }`

### **arrow** TBD
`label::arrow{ std::string }`


### **style**
for SVG canvas the most elegant way to (re-) define themes is through cascading stylesheets, or later if used in HTML document javascript. This 
	element is to allow direct embedding of `style tag` into the SVG file. see: [id](#id)

### **group**
Elements may be gathered into groups, and set certain attributes resulting in a cleaner, denser faster rendering.


## Attributes
### **rotate**
with lower left corner as pivot point all object may be rotated where the angle be either degrees or radians.

- `vertical` 90 degree rotation counter clock wise around lower left corner of object
- `horizontal` no rotation is applied
- `rotate::ccw{deg | rad}` counter clock wise rotation around pivot
- `rotate::cw{deg | rad}` clock wise rotation
- `rotate::angle{ deg | rad }`

### **align**
Context sensitive attribute with different meaning for [text](#text) elements and [position](#position) attribute. In case of 
text element aligns a block of text elements to `left | center | right`.
 
<svg width="200" height="100" viewBox="0 0 40 40" xmlns="http://www.w3.org/2000/svg">
	<text font-size="9" fill="grey" x="3" y="7">align::left</text>
	<svg x="0" y="10">
    <path d="M0,7 L100,7 M0,14 L100,14 M0,21 L100,21" stroke-dasharray="4 1" stroke="grey" stroke-width=".1" />
    <path d="M5,1 L5,25" stroke-dasharray="4 1" stroke="grey" stroke-width=".5" />
	<g fill="red" font-size="5" dominant-baseline="baseline">
    	<text x="5" y="7" text-anchor="start">Alberta</text>
    	<text x="5" y="14" text-anchor="start">Prince Edward Island</text>
    	<text x="5" y="21" text-anchor="start">New Brunswick</text>
	</g></svg>
</svg>
<svg width="200" height="100" viewBox="0 0 40 40" xmlns="http://www.w3.org/2000/svg">
	<text font-size="9" fill="grey" x="3" y="7">align::center</text>
	<svg x="0" y="10">
    <path d="M0,7 L100,7 M0,14 L100,14 M0,21 L100,21" stroke-dasharray="4 1" stroke="grey" stroke-width=".1" />
    <path d="M20,1 L20,25" stroke-dasharray="4 1" stroke="grey" stroke-width=".5" />
	<g fill="red" font-size="5" dominant-baseline="baseline">
    	<text x="20" y="7" text-anchor="middle">Ontario</text>
    	<text x="20" y="14" text-anchor="middle">Quebec</text>
    	<text x="20" y="21" text-anchor="middle">Manitoba</text>
	</g></svg>
</svg>
<svg width="200" height="100" viewBox="0 0 40 40" xmlns="http://www.w3.org/2000/svg">
	<text font-size="9" fill="grey" x="3" y="7">align::right</text>
	<svg x="0" y="10">
    <path d="M0,7 L100,7 M0,14 L100,14 M0,21 L100,21" stroke-dasharray="4 1" stroke="grey" stroke-width=".1" />
    <path d="M35,1 L35,25" stroke-dasharray="4 1" stroke="grey" stroke-width=".5" />
	<g fill="red" font-size="5" dominant-baseline="baseline">
    	<text x="35" y="7" text-anchor="end">Nunavut</text>
    	<text x="35" y="14" text-anchor="end">Saskatchewan</text>
    	<text x="35" y="21" text-anchor="end">Nova Scotia</text>
	</g></svg>
</svg>

In slightly different context alignment has meaning respect to position within a plot `x ::= left | center | right` and `y ::= top | center | bottom`

<svg width="400" height="100" viewBox="0 0 200 40" xmlns="http://www.w3.org/2000/svg">
	<text font-size="9" fill="grey" x="3" y="7">within chart</text>
	<svg x="0" y="10">
		<rect x="0" width="90" height="30"  fill="none" stroke="grey" stroke-dasharray="3 1" stroke-width=".1" />
    	<text x="70" y="7" font-size="5" text-anxhor="middle" fill="red" text-anchor="end">position{align::top, align::center}</text>
	</svg>
</svg>

### **horizontal**

### **vertical**
<svg width="200" height="100" viewBox="0 0 100 40" xmlns="http://www.w3.org/2000/svg">
	<text font-size="9" fill="grey" x="3" y="7">vertical text positioning</text>
	<svg x="0" y="10" >
		<rect x="0" width="90" height="30"  fill="none" stroke="grey" stroke-dasharray="3 1" stroke-width=".1" />
    	<text transform="rotate(-90 14 15)" x="0" y="7" font-size="5" fill="red" >vertical</text>
	</svg>
</svg>



### **color**
`color{0xffffff [,...]}`
All object may have a foreground or background color property, specified in hexadecimal colors. Will be extended to various palettes. In some cases
it makes sense to provide a set of colors, for example when controlling [legend](#legend)s

### **font**
`font{ std::string name [, weight::bold | weight::normal | weight::italic] ,unsigned size }`
selection may be applied to  elements: [`text`](#text) | [`footnote`](#footnote) | [`title`](#title)

### **position**
`position{x_pos , y_pos}` where 
```yacc
coordinate ::= unsigned int
x_pos ::= align::left | align::center | align::right | coordinate
y_pos ::= align::top | align::center | align::bottom | coordinate
```


### **stroke**
All geometric elements such as points, lines, circles or shapes including fonts have interior regions and outlines. With stroke you may control 
the attributes individually or placing them in a group.

To define and adjust: `linecap | linejoin | mittelimit`


### **opacity**
`opacity{float}`
`0 - 1.0` value to control the background or foreground of an element from transparent `0.0` to opaque `1.0`, useful to create translucent overlays, applied to group of elements. see: [`group`](#group)

### **id**
only for HTML like canvases such as SVG the `id{std::string}` is to define classes that may be identified in [DOM][405] and modified with [javascript][403] or [CSS][404]



[100]: https://www.wxwidgets.org/
[101]: https://wiki.wxwidgets.org/WxDC
[102]: https://www.cairographics.org/documentation/

[400]: http://h5cpp.org
[401]: http://sandbox.h5cpp.org/architecture/#error-handling
[402]: https://en.wikipedia.org/wiki/Scalable_Vector_Graphics
[403]: https://en.wikipedia.org/wiki/JavaScript
[404]: https://en.wikipedia.org/wiki/Cascading_Style_Sheets
[405]: https://en.wikipedia.org/wiki/Document_Object_Model
