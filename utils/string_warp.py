
s = """


Urgent: Soldiers needed. Please contact any border post if interested.


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