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
  ( Protocol p
  , Transport t
  ) => OpenCVThrift.OpenCV.Core.MatUtil.ToClient (Client p t) p t where
  toClient Client { matUtil = client } =
    OpenCVThrift.OpenCV.Core.MatUtil.toClient client

instance 
  ( Protocol p
  , Transport t
  ) => OpenCVThrift.OpenCV.Features2D.Features2D.ToClient (Client p t) p t where
  toClient Client { features2D = client } =
    OpenCVThrift.OpenCV.Features2D.Features2D.toClient client
