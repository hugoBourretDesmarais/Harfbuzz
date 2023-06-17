from fontTools.ttLib import TTFont, newTable

# Load the existing font
font = TTFont("Roboto-Bold.ttf")

# Create a new font
new_font = TTFont()

# Add necessary tables
new_font['head'] = newTable('head')
new_font['hhea'] = newTable('hhea')
new_font['maxp'] = newTable('maxp')
new_font['OS/2'] = newTable('OS/2')
new_font['hmtx'] = newTable('hmtx')
new_font['glyf'] = newTable('glyf')

# Define the glyphs for 0-9
glyph_names = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]

# Initialize metrics and glyphs dictionary
new_font['hmtx'].metrics = {}
new_font['glyf'].glyphs = {}

# Copy the glyph metrics for 0-9 to the new font and also copy the glyphs
for glyph_name in glyph_names:
    glyph = font['glyf'][glyph_name]
    new_font['glyf'].glyphs[glyph_name] = glyph
    new_font['hmtx'].metrics[glyph_name] = font['hmtx'].metrics[glyph_name]

# Count glyphs and set numGlyphs attribute in 'maxp' table
new_font['maxp'].numGlyphs = len(new_font['glyf'].glyphs)

# Save the new font as a TTF
new_font.save("myOwnFont.ttf")
