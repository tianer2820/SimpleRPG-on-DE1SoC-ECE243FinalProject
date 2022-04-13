
s = """


You want to try? The ruin is at the end of this road. No one have ever successfully broken the spell, but if you did, don't forget who pointed you the way! Wish you the best luck.



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