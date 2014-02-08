module OpenCV where

import Thrift.Protocol
import Thrift.Transport

import qualified OpenCV.Core.MatUtil
import qualified OpenCV.Features2D.Features2D

data Client p t = Client 
  { matUtil :: OpenCV.Core.MatUtil.Client p t
  , features2D :: OpenCV.Features2D.Features2D.Client p t
  }

instance 
  ( Protocol p
  , Transport t
  ) => OpenCV.Core.MatUtil.ToClient (Client p t) p t where
  toClient Client { matUtil = client } =
    OpenCV.Core.MatUtil.toClient client

instance 
  ( Protocol p
  , Transport t
  ) => OpenCV.Features2D.Features2D.ToClient (Client p t) p t where
  toClient Client { features2D = client } =
    OpenCV.Features2D.Features2D.toClient client
