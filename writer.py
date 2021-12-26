import numpy 
from PIL import Image


def get_image(image_path):
    """Get a numpy array of an image so that one can access values[x][y]."""
    image = Image.open(image_path, "r")
    width, height = image.size
    pixel_values = list(image.getdata())
    if image.mode == "RGBA8":
        channels = 4
    elif image.mode == "P":
        channels = 1
    else:
        print("Unknown mode: %s" % image.mode)
        return None
    pixel_values = numpy.array(pixel_values).reshape((width, height, channels))
    return pixel_values

for i in range(1, 3):
    image = get_image(f"Trees/Tree_{i}.bmp")
    with open(f"RGBA8/Tree_{i}.txt", "w") as file:
        for i in image.shape:
            file.write(str(i))
            file.write(" ")
        for row in image:
            for col in row:
                for i in col:
                    file.write(str(i))
                    file.write(" ")