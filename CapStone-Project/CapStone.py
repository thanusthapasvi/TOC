import random
import string
import collections
from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives.asymmetric import rsa
from cryptography.hazmat.primitives import serialization
from cryptography.hazmat.primitives.asymmetric import padding
from PIL import Image

def caesar_cipher(text, shift):
    encrypted_text = ''
    for char in text:
        if char.isalpha():
            shifted = chr((ord(char) - ord('a' if char.islower() else 'A') + shift) % 26 + ord('a' if char.islower() else 'A'))
            encrypted_text += shifted
        else:
            encrypted_text += char
    return encrypted_text

def rsa_encrypt(text):
    private_key = rsa.generate_private_key(
        public_exponent=65537,
        key_size=2048,
        backend=default_backend()
    )
    public_key = private_key.public_key()
    ciphertext = public_key.encrypt(
        text.encode(),
        padding.OAEP(
            mgf=padding.MGF1(algorithm=hashes.SHA256()),
            algorithm=hashes.SHA256(),
            label=None
        )
    )
    return ciphertext

def generate_random_key(length):
    return ''.join(random.choices(string.ascii_letters + string.digits, k=length))

def calculate_frequency(text):
    frequency = collections.Counter(text.lower())
    total_characters = sum(frequency.values())
    frequency_percentage = {char: count / total_characters * 100 for char, count in frequency.items()}
    return frequency_percentage

def hide_message_in_image(image_path, message):
    image = Image.open(image_path)
    width, height = image.size
    message_length = len(message)
    if message_length > (width * height):
        raise ValueError("Message too long to hide in image")
    binary_message = ''.join(format(ord(char), '08b') for char in message)
    pixel_index = 0
    for char in binary_message:
        x = pixel_index % width
        y = pixel_index // width
        pixel = list(image.getpixel((x, y)))
        pixel[-1] = (pixel[-1] & 254) | int(char)
        image.putpixel((x, y), tuple(pixel))
        pixel_index += 1
    image.save('hidden_message_image.png')

text = input("Enter a text message to encrypt : ")
print("Original Text:", text)

caesar_encrypted = caesar_cipher(text, 3)
print("\nCaesar Cipher Encrypted Text:", caesar_encrypted)

rsa_encrypted = rsa_encrypt(text)
print("\nRSA Encrypted Text:", rsa_encrypted)

random_key = generate_random_key(16)
print("\nRandomly Generated Key:", random_key)

frequency = calculate_frequency(text)
print("\nFrequency Analysis:", frequency)

hide_message_in_image("C:/Users/t4872/Pictures/Screenshots/Screenshot (10).png", "Secret Message")
print("\nMessage hidden in image successfully")
