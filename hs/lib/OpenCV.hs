module OpenCV where

{-import qualified MatUtil_Client-}
{-import qualified Features2D_Client-}
{-import OpenCVTypes-}
{-import MatUtil_Iface-}

{-import Thrift-}
{-import Thrift.Protocol.Binary-}
{-import Thrift.Transport-}
{-import Thrift.Transport.Handle-}
{-import Thrift.Server-}

import Thrift.Protocol
import Thrift.Transport

import qualified OpenCV.Core.MatUtil
import qualified OpenCV.Features2D.Features2D

-- We're assuming all sub-clients use the same protocol and transport types.
{-data OpenCVClient mu f2d p t = -}
  {-( OpenCV.Core.MatUtil.Client mu p t-}
  {-, OpenCV.Features2D.Features2D.Client f2d p t) => OpenCVClient-}
    {-{ matUtil :: mu-}
    {-, features2D :: f2d-}
    {-}-}

{-instance-}
  {-( Thrift.Protocol.Protocol p-}
  {-, Thrift.Transport.Transport t) => -}
    {-OpenCV.Core.MatUtil.Client (OpenCVClient mu f2d p t) p t where-}
      {-cast OpenCVClient { matUtil = client } = -}
        {-OpenCV.Core.MatUtil.cast client-}

{-instance-}
  {-( Thrift.Protocol.Protocol p-}
  {-, Thrift.Transport.Transport t) => -}
    {-OpenCV.Features2D.Features2D.Client (OpenCVClient mu f2d p t) p t where-}
      {-cast OpenCVClient { features2D = client } = -}
        {-OpenCV.Features2D.Features2D.cast client-}

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
