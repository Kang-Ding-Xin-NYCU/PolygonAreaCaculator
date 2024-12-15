################################
 Polygons Area Calculator
################################

*******************************
Project Info
*******************************
**Project**: PolygonAreaCaculator

**GitHub**: https://github.com/Kang-Ding-Xin-NYCU/PolygonAreaCaculator
*******************************
System Architecture
*******************************
**Input** : 
    - The vertices of a polygon

**Process** : 
    - Calculate the area of polygon by using its coordinates and determinant

**Output** : 
    - A picture of polygon
    - Area of polygon
    - A list of coordinates of the polygon
*******************************
API Description
*******************************
.. code:: c++

    class polygon{
        vector<double> vertices;
        double area;
    };

.. code:: python

    class polygon:
        def set_vertices:
        def get_vertices:
        def area:
        def plot:

*******************************
How to use it
*******************************
#. Clone the file::

   $ git clone https://github.com/Kang-Ding-Xin-NYCU/PolygonAreaCaculator.git

#. Install requirement::

   $ pip install -r requirement.txt

#. Compile file::

   $ make

*******************************
How to make file
*******************************
#. Compile file::

   $ make

#. Removing compiled files::

   $ make clean

#. Test file::

   $ make test

****************************
 Engineering Infrastructure
****************************

- Build : Make
- Version control : git

************
 References
************
- 利用行列式計算多邊形面積 :
     https://ccjou.wordpress.com/2012/05/09/%E5%88%A9%E7%94%A8%E8%A1%8C%E5%88%97%E5%BC%8F%E8%A8%88%E7%AE%97%E5%A4%9A%E9%82%8A%E5%BD%A2%E9%9D%A2%E7%A9%8D/
