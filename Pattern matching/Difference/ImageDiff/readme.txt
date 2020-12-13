Algorithm:
1.If images have unequal width/height, different.
2.Xor the image bitmaps.
3.Scan resulting difference bitmap for non-zero bytes
4.If found non-zero byte, different.(display xor bitmap)
 OpenCL arrays can be used for speed.
