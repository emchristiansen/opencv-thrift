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

import qualified OpenCV.Core.MatUtil

data OpenCVProtocol a = 
  OpenCV.Core.MatUtil.IsProtocol a => OpenCVProtocol
    { matUtilProtocol :: a
    }

instance OpenCV.Core.MatUtil.IsProtocol (OpenCVProtocol a) where
  cast OpenCVProtocol { matUtilProtocol = matUtil } = 
    OpenCV.Core.MatUtil.cast matUtil
