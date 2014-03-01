--
-- Licensed to the Apache Software Foundation (ASF) under one
-- or more contributor license agreements. See the NOTICE file
-- distributed with this work for additional information
-- regarding copyright ownership. The ASF licenses this file
-- to you under the Apache License, Version 2.0 (the
-- "License"); you may not use this file except in compliance
-- with the License. You may obtain a copy of the License at
--
--   http://www.apache.org/licenses/LICENSE-2.0
--
-- Unless required by applicable law or agreed to in writing,
-- software distributed under the License is distributed on an
-- "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
-- KIND, either express or implied. See the License for the
-- specific language governing permissions and limitations
-- under the License.
--

{-import qualified MatUtil_Client as MatUtil-}
{-import qualified Features2D_Client as Features2D-}
{-import Mat_Types-}

{-import OpenCV-}
{-import OpenCVTypes-}
{-import OpenCV.Core.MatUtil-}

import OpenCVLocalhost
import qualified OpenCVLocalhost

import Thrift
import Thrift.Protocol.Binary
import Thrift.Transport
import Thrift.Transport.Handle
import Thrift.Server

import Data.Maybe
import Text.Printf
import Network
import qualified Data.Vector as V 

{-import System.Directory-}
{-import System.FilePath.Posix-}
{-import Data.Char-}
import Codec.Picture
import Codec.Picture.Types
{-import Text.Printf-}
{-import Control.Arrow ((&&&))-}
{-import Data.Word (Word8)-}
{-import Data.Vector.Storable (Vector)-}

import OpenCVThrift
import OpenCVThrift.OpenCV
import OpenCVThrift.OpenCV.Core

import OpenCVThrift.OpenCV.Core.MatUtil
import OpenCVThrift.OpenCV.Features2D.Features2D
import Control.Exception

type ImageRGBA8 = Image PixelRGBA8

instance Show (Image PixelRGBA8) where
  show image = show $ (imageWidth image, imageHeight image)

transcodeToImageRGBA8 :: DynamicImage -> Maybe (ImageRGBA8)
transcodeToImageRGBA8 dynamicImage = case dynamicImage of
  ImageY8 image -> Just $ promoteImage image
  ImageYA8 image -> Just $ promoteImage image
  ImageRGB8 image -> Just $ promoteImage image
  ImageRGBA8 image -> Just $ promoteImage image
  ImageYCbCr8 image -> Just $ 
    promoteImage (convertImage image :: Image PixelRGB8)
  ImageCMYK8 image -> Just $ 
    promoteImage (convertImage image :: Image PixelRGB8)
  _ -> Nothing

-- Attempts to read an `ImageRGBA8` from the given `FilePath`.
readImageSafe :: FilePath -> IO (Maybe ImageRGBA8)
readImageSafe filePath = do
  putStrLn $ "Reading " ++ filePath
  eitherImage <- readImage filePath
  case eitherImage of
  	Right image -> case transcodeToImageRGBA8 image of
  	  Nothing -> do
  	    putStrLn $ "Could not transcode image to PNG, skipping: " ++ filePath
  	    return Nothing
  	  transcoded -> return transcoded
  	Left errorMessage -> do
  	  let formatString = "Failed to read %s with error: %s.\nSkipping."
  	  putStrLn $ printf formatString filePath errorMessage
  	  return Nothing

cvType = T64FC1

{-matUnpacked = MatUnpacked -}
  {-(Just 3) -}
  {-(Just 2) -}
  {-(Just 1) -}
  {-(Just $ V.fromList [1, 2, 3, 4, 5, 6])-}

main = do
  putStrLn "Start"

  client <- OpenCVLocalhost.openCVClient

  Just image <- readImageSafe "../data/burningMan.jpg"
  putStrLn $ show image

  let 
    {-height = imageHeight image-}
    {-width = imageWidth image-}
    height = 5
    width = 6
    pixels :: [Double]
    pixels = concat $ do
      row <- [0 .. height - 1]
      column <- [0 .. width - 1]
      let (PixelRGBA8 r g b a) = pixelAt image column row
      {-return [fromIntegral r, fromIntegral g, fromIntegral b] -}
      {-return [fromIntegral r] -}
      return [fromIntegral $ row * width + column] 
    imageMat = MatUnpacked
      (Just $ fromIntegral height)
      (Just $ fromIntegral width)
      (Just 1)
      (Just $ V.fromList pixels)

  

  putStrLn $ show imageMat

  packed <- pack client cvType imageMat
  unpacked <- unpack client packed

  putStrLn $ show unpacked

  putStrLn $ show $ imageMat == unpacked

  putStrLn "Done"

