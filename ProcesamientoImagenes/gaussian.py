# -*- coding: utf-8 -*-
"""Gaussian_blur_kernel.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1nn6HOQDC2-948S_4TT0X8-TD7EHMMESm

# FILTRO GAUSSIAN BLUR A01770169

Aqui se ilustra la convolucion. Este tutorial consta de tres pasos.

1. Descargar una imagen
2. Dependencias
3. Aplicar una convolucion

$f(x,y) * g(x,y)$


$g(x,y) = \frac{1}{2\pi\sigma^2} e^{-\frac{x^2+y^2}{2\sigma^2}}$

## Descarga de Imagen
"""

'''
!gdown https://drive.google.com/uc?id=1aURFCCD4AAaOUH6busVppIn4ruI_ZTg4

!ls -ltr

"""## Dependencias"""
'''

import matplotlib.pyplot as plt
import numpy
from PIL import Image
from scipy import ndimage

"""## Convolucion

Aqui se abre y normaliza la imagen
"""

'''
Is = Image.open('gato.png');
I = Is.convert('L');
I = numpy.asarray(I);
I = I / 255.0;
'''

"""Seleccionar los kernels y aplicar la convolucion"""

def gaussian(I, Is, sigma, size):
  A= numpy.zeros((size,size))
  
  for x in range(-size//2,size//2+1):
    for y in range (-size//2,size//2+1):
      A[x][y] = 1/(2*numpy.pi*sigma**2)*(numpy.exp(-(x**2 + y**2)/(2*sigma**2)))

  Ig = ndimage.convolve(I, A, mode='constant', cval=0.0)

  plt.figure(figsize = (15,15))

  plt.subplot(2,2,1)
  plt.imshow(Is)
  plt.xlabel('Input Image')

  plt.subplot(2,2,2)
  plt.imshow(Ig)
  plt.xlabel('Gaussian Blur Kernel')

  return A


'''
plt.grid(False)
plt.show()
'''