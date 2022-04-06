import xml
from xml.dom import minidom



"""
<tile id="1">
  <properties>
   <property name="is_solid" type="bool" value="false"/>
  </properties>
 </tile>
"""

# parse an xml file by name
file: minidom.Document = minidom.parse('utils/main set.tsx')

#use getElementsByTagName() to get tag
tiles = file.getElementsByTagName('tile')

solid_list = [False for i in range(len(tiles))]
for i, tile in enumerate(tiles):
    tile_id = int(tile.attributes['id'].value)
    tile_props = tile.getElementsByTagName('property')
    for tile_prop in tile_props:
        prop_name = tile_prop.attributes['name'].value
        if prop_name == 'is_solid':
            prop_value = str(tile_prop.attributes['value'].value)
            if prop_value.lower() == 'true':
                solid_list[tile_id] = True
            else:
                solid_list[tile_id] = False
            break

byte_list = []
bit_filled = 0
current_byte = 0
for solid in solid_list:
    current_byte = current_byte << 1
    if solid:
        current_byte |= 1
    bit_filled += 1
    if bit_filled == 8:
        byte_list.append(current_byte)
        current_byte = 0
        bit_filled = 0

if bit_filled > 0:
    current_byte = current_byte << (8 - bit_filled)
    byte_list.append(current_byte)
    current_byte = 0
    bit_filled = 0

print('{\n', end='')
i = 0
for b in byte_list:
    print('{}, '.format(hex(b)), end='')
    i += 1
    if i % 8 == 0:
        print('\n', end='')
print('};\n', end='')