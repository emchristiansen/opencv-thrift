module OpenCV.Core.MatUtil where

import Mat_Types

class MatUtil a where
  pack :: a -> CVType -> MatUnpacked -> IO Mat 
