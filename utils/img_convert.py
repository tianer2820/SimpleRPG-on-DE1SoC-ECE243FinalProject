import PIL
from PIL import Image
import os
join = os.path.join

OUT_FILE = 'utils/resources.h'
SRC_DIR = 'utils/imgs'
imgs = os.listdir(SRC_DIR)

HEADER_HEAD = """
#if !defined(RESOURCES_H)
#define RESOURCES_H

"""

HEADER_TAIL = """
#endif // RESOURCES_H
"""

with open(OUT_FILE, 'wt', encoding='utf8') as f:
    f.write(HEADER_HEAD)

    for img in imgs:
        full_path = join(SRC_DIR, img)
        image = Image.open(full_path)
        image = image.convert('RGBA')
        
        data = []
        mask = []
        mask_byte = 0
        i = 0
        for y in range(image.height):
            for x in range(image.width):
                r, g, b, a = image.getpixel((x, y))
                r = r * 0b11111 // 255
                g = g * 0b111111 // 255
                b = b * 0b11111 // 255
                short = r << 11 | g << 5 | b
                data.append(short)
                mask_byte = (mask_byte << 1) | int(a > 127)

                i += 1
                if i % 8 == 0:
                    mask.append(mask_byte)
                    mask_byte = 0
        if i % 8 != 0:
            add_zeros = 8 - i%8
            mask_byte = mask_byte << add_zeros
            mask.append(mask_byte)
        
        print(img, len(data), len(mask))
        res_name, _ = os.path.splitext(img)
        res_name = res_name.replace(' ', '_')
        res_name = res_name.replace('.', '_')
        res_name = res_name.replace('-', '_').upper()
        print(res_name)
        # w and h
        f.write("const unsigned int RES_{}_W = {};\n".format(res_name, image.width))
        f.write("const unsigned int RES_{}_H = {};\n".format(res_name, image.height))

        f.write('const short RES_{}_DATA[] = {{'.format(res_name))
        for i, short in enumerate(data):
            if i % 8 == 0:
                f.write('\n')
            f.write('{}, '.format(hex(short)))
        f.write('};\n\n')

        f.write('const unsigned char RES_{}_MASK[] = {{'.format(res_name))
        for i, b in enumerate(mask):
            if i % 8 == 0:
                f.write('\n')
            f.write('{}, '.format(hex(b)))
        f.write('};\n\n\n')

    f.write(HEADER_TAIL)