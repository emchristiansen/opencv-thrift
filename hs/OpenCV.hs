module OpenCV where

import qualified MatUtil_Client
import qualified Features2D_Client
import OpenCVTypes
import MatUtil_Iface

import Thrift
import Thrift.Protocol.Binary
import Thrift.Transport
import Thrift.Transport.Handle
import Thrift.Server

import Data.Maybe
import Text.Printf
import Network
import Data.Vector
import Data.Text.Lazy

import GHC.IO.Handle.Types

type BinaryProtocolPair = (BinaryProtocol GHC.IO.Handle.Types.Handle, BinaryProtocol GHC.IO.Handle.Types.Handle)

client :: (BinaryProtocol GHC.IO.Handle.Types.Handle, BinaryProtocol GHC.IO.Handle.Types.Handle)
client = undefined

data OpenCV

class MatUtilService a where
  pack :: a -> CVType -> MatUnpacked -> IO Mat
  
{-instance OpenCV MatUtilService where-}
  {-pack -}

{-instance OpenCV MatUtil_Iface where-}
  {-pack OpenCV = MatUtil_client.pack -}

viaMatUtil :: (BinaryProtocolPair -> a) -> IO a
viaMatUtil function = do
  putStrLn "Connecting to MatUtil."
  transport  <- hOpen ("localhost", PortNumber 9090)
  let binProto = BinaryProtocol transport
  return $ function (binProto, binProto)

{-pack :: CVType -> MatUnpacked -> IO Mat-}
{-pack = MatUtil_Client.pack client  -}
{-pack :: CVType -> MatUnpacked -> IO Mat-}
{-pack a b = do -}
  {-function <- viaMatUtil MatUtil_Client.pack-}
  {-function a b-}
{-pack a b = (viaMatUtil MatUtil_Client.pack) . liftM0-}

detect :: Text -> Mat -> IO (Vector KeyPoint)
detect = Features2D_Client.detect client 
