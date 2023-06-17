import fontforge

# Load the existing font
font = fontforge.open("Roboto-Bold.ttf")

# Create a new font
new_font = fontforge.font()

# Copy the glyphs for 0-9 to the new font
for char in "0123456789":
    # Clear the selection
    font.selection.none()
    # Select the glyph for the character
    font.selection.select(ord(char))
    # Copy it
    font.copy()
    # Paste it into the new font
    new_font.selection.select(ord(char))
    new_font.paste()

# Save the new font as a TTF
new_font.generate("myOwnFont.ttf")
