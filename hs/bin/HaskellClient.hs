--
-- Licensed to the Apache Software Foundation (ASF) under one
-- or more contributor license agreements. See the NOTICE file
-- distributed with this work for additional information
-- regarding copyright ownership. The ASF licenses this file
-- to you under the Apache License, Version 2.0 (the
-- "License"); you may not use this file except in compliance
-- with the License. You may obtain a copy of the License at
--
--   http://www.apache.org/licenses/LICENSE-2.0
--
-- Unless required by applicable law or agreed to in writing,
-- software distributed under the License is distributed on an
-- "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
-- KIND, either express or implied. See the License for the
-- specific language governing permissions and limitations
-- under the License.
--

{-import qualified MatUtil_Client as MatUtil-}
{-import qualified Features2D_Client as Features2D-}
{-import Mat_Types-}

import OpenCV
import OpenCVTypes

import Thrift
import Thrift.Protocol.Binary
import Thrift.Transport
import Thrift.Transport.Handle
import Thrift.Server

import Data.Maybe
import Text.Printf
import Network
import Data.Vector

{-data Service = MatUtil-}

{-getService :: String -> PortID -> IO Int-}
getService name port = do
  putStrLn $ printf "Connecting to %s." name
  transport  <- hOpen ("localhost", port)
  let binProto = BinaryProtocol transport
  return (binProto, binProto)

cvType = CV_32FC1

matUnpacked = MatUnpacked 
  (Just 3) 
  (Just 2) 
  (Just 1) 
  (Just $ fromList [1, 2, 3, 4, 5, 6])

main = do
  putStrLn "HERE"
  matUtilClient <- getService "MatUtil" $ PortNumber 9090 
  packed <- OpenCV.pack cvType matUnpacked
  putStrLn $ show packed
  {-transport  <- hOpen ("localhost", PortNumber 9090)-}
  {-let binProto = BinaryProtocol transport-}
  {-let client = (binProto, binProto)-}

  {-Client.hello_func client-}
  
  {-sum <- Client.add client 3 4-}
  {-putStrLn $ show sum-}

  {-Client.ping client-}
  {-print "ping()"-}

  {-sum <- Client.add client 1 1-}
  {-printf "1+1=%d\n" sum-}


  {-let work = Work { f_Work_op = Just DIVIDE,-}
                    {-f_Work_num1 = Just 1,-}
                    {-f_Work_num2 = Just 0,-}
                    {-f_Work_comment = Nothing-}
                  {-}-}

  {--- TODO - get this one working-}
  {---catch (Client.calculate client 1 work) (\except ->-}
  {---     printf "InvalidOp %s" (show except))-}


  {-let work = Work { f_Work_op = Just SUBTRACT,-}
                    {-f_Work_num1 = Just 15,-}
                    {-f_Work_num2 = Just 10,-}
                    {-f_Work_comment = Nothing-}
                  {-}-}

  {-diff <- Client.calculate client 1 work-}
  {-printf "15-10=%d\n" diff-}

  {-log <- SClient.getStruct client 1-}
  {-printf "Check log: %s\n"  $ fromJust $ f_SharedStruct_value log-}

  -- Close!
  {-tClose transport-}
  putStrLn "Done"
