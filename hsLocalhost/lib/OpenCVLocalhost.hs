module OpenCVLocalhost where

import qualified OpenCV
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

import qualified OpenCV.Core.MatUtil
import qualified OpenCV.Features2D.Features2D

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
matUtilPort = PortNumber 9090

features2DPort :: PortID
features2DPort = PortNumber 9091

matUtilClient :: IO (OpenCV.Core.MatUtil.Client BinaryProtocol Handle)
matUtilClient = OpenCV.Core.MatUtil.Client <$> getService 
  "MatUtil" 
  matUtilPort

features2DClient :: IO (OpenCV.Features2D.Features2D.Client BinaryProtocol Handle)
features2DClient = OpenCV.Features2D.Features2D.Client <$> getService 
  "Features2D" 
  features2DPort

openCVClient :: IO (OpenCV.Client BinaryProtocol Handle)
openCVClient = OpenCV.Client 
  <$> matUtilClient 
  <*> features2DClient

{-openCVLocalhostProtocol = do-}
  {-matUtil <- getService "MatUtil" 9090-}
  {-return $ OpenCV.OpenCVProtocol matUtil-}

