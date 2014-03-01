module OpenCVLocalhost where

{-import qualified Internal.Util-}

{-import qualified OpenCV.Core.MatUtil-}
{-import OpenCV.Core.MatUtil-}

import Thrift
import Thrift.Protocol
import Thrift.Protocol.Binary
import Thrift.Transport
import Thrift.Transport.Handle
import Thrift.Server

import Data.Maybe
import Text.Printf
import Network
import Data.Vector

import Control.Applicative

{-import qualified GHC.IO.Handle.Types-}
import GHC.IO.Handle.Types (Handle)

import qualified OpenCVThrift
import qualified OpenCVThrift.OpenCV
import qualified OpenCVThrift.OpenCV.Core.MatUtil
import qualified OpenCVThrift.OpenCV.Features2D.Features2D

type ClientValue = 
  ( BinaryProtocol Handle
  , BinaryProtocol Handle
  )

{-data Service = MatUtil-}

getService :: String -> PortID -> IO ClientValue
{-getService :: (Protocol p, Transport t) => String -> PortID -> IO (p t, p t)-}
getService name port = do
  putStrLn $ printf "Connecting to %s." name
  transport  <- hOpen ("localhost", port)
  let binProto = BinaryProtocol transport
  return (binProto, binProto)

{-matUtilService = OpenCV.Core.MatUtil.Client $ getService "MatUtil" $ PortNumber 9090-}

matUtilPort :: PortID
matUtilPort = PortNumber $ fromIntegral $ 
  OpenCVThrift.basePort + OpenCVThrift.matUtilPortOffset

features2DPort :: PortID
features2DPort = PortNumber $ fromIntegral $ 
  OpenCVThrift.basePort + OpenCVThrift.features2DPortOffset

matUtilClient :: IO (OpenCVThrift.OpenCV.Core.MatUtil.Client BinaryProtocol Handle)
matUtilClient = OpenCVThrift.OpenCV.Core.MatUtil.Client <$> getService 
  "MatUtil" 
  matUtilPort

features2DClient :: IO (OpenCVThrift.OpenCV.Features2D.Features2D.Client BinaryProtocol Handle)
features2DClient = OpenCVThrift.OpenCV.Features2D.Features2D.Client <$> getService 
  "Features2D" 
  features2DPort

openCVClient :: IO (OpenCVThrift.OpenCV.Client BinaryProtocol Handle)
openCVClient = OpenCVThrift.OpenCV.Client 
  <$> matUtilClient 
  <*> features2DClient


