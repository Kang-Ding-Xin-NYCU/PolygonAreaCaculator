import polygon

#set vertices by list of list
vertice = [[100, 100], [400, 100], [400, 400], [100, 400]]
vertice1 = [[150, 150], [250, 150], [250, 250], [150, 250]]
vertice2 = [[300, 300], [350, 300], [350, 350], [300, 350]]
#initialize a polygon by vertices list
polygon_test = polygon.polygon(vertice)
#insert islands into polygon
polygon_test.set_islands([vertice1, vertice2])
#get polygon's area
polygon_test.area()
#set image file name and image size
savefile = "polygon.png"
polygon_test.plot(savefile, 500, 500)