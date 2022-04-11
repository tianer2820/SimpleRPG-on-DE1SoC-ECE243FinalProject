
s = """
This is our third attempt on this dungeon. We finally came to the bottom this time. With no luck, we found nothing here except books with symbols we can't read. We are taking them back anyway. Maybe they worth something.
"""

threshold = (320 - 5*2) // 6


lines = []
current_line = []
s = s.replace('\n', '')
words = s.split(' ')
line_length = 0
for word in words:
    if line_length + len(word) > threshold:
        # newline
        lines.append(" ".join(current_line))
        current_line = [word]
        line_length = len(word) + 1
    else:
        current_line.append(word)
        line_length += len(word) + 1
if len(current_line) > 0:
    lines.append(" ".join(current_line))

print('\\n\\\n'.join(lines))