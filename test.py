import polygon

vertice = [[100, 100], [400, 100], [400, 400], [100, 400]] 
vertice1 = [[150, 150], [200, 150], [200, 200], [150, 200]] 
vertice2 = [[200, 200], [350, 200], [350, 350], [200, 350]]
vertice3 = [[325, 325], [345, 325], [345, 345], [325, 345]]
vertice4 = [[330, 330], [340, 330], [340, 340], [330, 340]]
polygon_a = polygon.polygon(vertice1)
polygon_b = polygon.polygon(vertice2)
polygon_c = polygon.polygon(vertice3)
polygon_d = polygon.polygon(vertice4)

polygon_b.set_islands([polygon_c, polygon_d])
print(polygon_a.get_islands())
print(polygon_b.get_islands())
    
polygon_test = polygon.polygon(vertice)
polygon_test.set_islands([polygon_a, polygon_b])
print(polygon_test.get_islands())

print((polygon_test.get_islands())[0].get_islands())
print((polygon_test.get_islands())[1].get_islands())

savefile = "polygon.png"
polygon_test.plot(savefile, 500, 500)