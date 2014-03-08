module OpenCVThrift.OpenCV where

import Thrift.Protocol
import Thrift.Transport

import qualified OpenCVThrift.OpenCV.Core.MatUtil
import qualified OpenCVThrift.OpenCV.Features2D.Features2D

data Client p t = Client
  { matUtil :: OpenCVThrift.OpenCV.Core.MatUtil.Client p t
  , features2D :: OpenCVThrift.OpenCV.Features2D.Features2D.Client p t
  }

instance 
  OpenCVThrift.OpenCV.Core.MatUtil.ToClient (Client p t) p t where
  toClient Client { matUtil = client } =
    OpenCVThrift.OpenCV.Core.MatUtil.toClient client

instance 
  OpenCVThrift.OpenCV.Features2D.Features2D.ToClient (Client p t) p t where
  toClient Client { features2D = client } =
    OpenCVThrift.OpenCV.Features2D.Features2D.toClient client
    
newtype OpenCVComputation a = OpenCVComputation 
  { runOpenCVComputation :: forall p t. Client p t -> IO a 
  }

instance Monad OpenCVComputation where
  OpenCVComputation closure >>= f = OpenCVComputation $ \client -> do
    value <- closure client 
    let OpenCVComputation closure' = f value
    closure' client
  return x = OpenCVComputation $ \client -> return x

convert0 :: (forall p t. Client p t -> IO a) -> OpenCVComputation a
convert0 f = OpenCVComputation f

convert1 :: (forall p t. Client p t -> b1 -> IO a) -> b1 -> OpenCVComputation a
convert1 f arg1 = OpenCVComputation $ \client -> f client arg1

convert2 :: (forall p t. Client p t -> b1 -> b2 -> IO a) -> b1 -> b2 -> OpenCVComputation a
convert2 f arg1 arg2 = OpenCVComputation $ \client -> f client arg1 arg2

convert3 :: (forall p t. Client p t -> b1 -> b2 -> b3 -> IO a) -> b1 -> b2 -> b3 -> OpenCVComputation a
convert3 f arg1 arg2 arg3 = OpenCVComputation $ \client -> f client arg1 arg2 arg3

{-instance -}
  {-( Protocol p-}
  {-, Transport t-}
  {-) => OpenCVThrift.OpenCV.Core.MatUtil.ToClient (Client p t) p t where-}
  {-toClient Client { matUtil = client } =-}
    {-OpenCVThrift.OpenCV.Core.MatUtil.toClient client-}

{-instance -}
  {-( Protocol p-}
  {-, Transport t-}
  {-) => OpenCVThrift.OpenCV.Features2D.Features2D.ToClient (Client p t) p t where-}
  {-toClient Client { features2D = client } =-}
    {-OpenCVThrift.OpenCV.Features2D.Features2D.toClient client-}
