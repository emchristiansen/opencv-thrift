module OpenCV.Core.MatUtil where

import Thrift
import Thrift.Protocol.Binary
import Thrift.Transport
import Thrift.Transport.Handle
import Thrift.Server

import Mat_Types
import qualified MatUtil

{-data MatUtilClient a = MatUtilClient a-}

{-type Client = Int-}

{-class MatUtilClient a where-}
  {-cast :: a -> Client -}

{-class MatUtilClient a => MatUtil a where-}
  {-pack :: a -> CVType -> MatUnpacked -> IO Mat -}
  {-pack client cvType matUnpacked = -}
    {-MatUtil.pack undefined cvType matUnpacked-}
